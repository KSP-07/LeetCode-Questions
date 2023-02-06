//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <sstream>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
vector<Node*> bfs(Node *src){
    vector<Node*>ans;
    map<Node*, bool> visit;
    queue<Node*> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty()) {
        Node *u = q.front();
        ans.push_back(u);
        q.pop();
        vector<Node *> v = u->neighbors;
        int n = v.size();
        for (int i = 0; i < n; i++){
            if (!visit[v[i]]){
                visit[v[i]] = true;
                q.push(v[i]);
            }
        }
    }
    return ans;
}
bool checkedClone(Node* prev, Node* new1 ) {
    vector<Node*>prevAns = bfs(prev);
    vector<Node*>newAns = bfs(new1);
    for (int i = 0; i < prevAns.size(); i++) {
        // cout << prevAns[i] << " " << newAns[i] << endl;
        if (prevAns[i] == newAns[i]) {
            // cout << "hii";
            return false;
        }
    }
    return true;
}


// } Driver Code Ends
//User function Template for C++

// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
public:

//using dfs algo

    void dfs(Node* node , Node* head , auto &vis){
        vis[head->val]=head;   //yaha pe node isliye store krra rhe kuki...hume baad mai chiye hoga , jaise graph hai , 1-> 2,3..2->1,3..3->2,1
        //toh ab 2 pe aane ke baad 3 pe toh jaa skte, pr 1 visited aayga na..to vis[1] pe uska pointer rkh lia aur neighbour mai push kredenge 2 ke
        
        for(auto it : node->neighbors){
            //agar kabi visit nhi kia toh new node create hogi uss element kii
            if(vis[it->val]==NULL){
                Node* newNode = new Node(it->val);
                (head->neighbors).push_back(newNode);  //ab jo main node thii...ye uske neighbours thee..toh ye neighbours mai push kr hee
                dfs(it , newNode , vis);   //isme curr node ab main node hogyy original G mai, aur newNode humari clone mai main hogyy
            }
            
            //ab jab node phle se visited hai aur firse aaya mtlb neighbour hai,  to uska sirf pointer push krdia
            else{
                (head->neighbors).push_back(vis[it->val]);  //for ex 1-2 aay aur 2-3 hai aur 2-1 hai  ,to 2-1 ke case mai 1 ka address laay 2 ke neighbour mai
            }
        }
        
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        
        vector<Node*> vis(1000 , NULL);
        Node* head = new Node(node->val);   //ek naya graph bana rahe
        dfs(node , head , vis);
        return head;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Node* root = NULL;
        vector<Node*>v(N);
        std::string buffer;
        std::getline(std::cin, buffer);
        for (int i = 0; i < N; i++)v[i] = new Node(i);
        for (int i = 0; i < N; i++) {
            std::vector<Node*> vec;
            std::string buffer;
            int data;
            std::getline(std::cin, buffer);
            std::istringstream iss(buffer);
            while (iss >> data)
                vec.push_back(v[data]);
            v[i]->neighbors = vec;
        }
        Solution ob;
        vector<Node*>prev = bfs(v[0]);
        Node* ans = ob.cloneGraph(v[0]);
        vector<Node*>now = bfs(ans);
        cout << checkedClone(v[0], ans) << endl;

    }
    return 0;
}
// } Driver Code Ends