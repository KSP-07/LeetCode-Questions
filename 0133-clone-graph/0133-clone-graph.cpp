/*
// Definition for a Node.
class Node {
public:
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
*/


/*

GFG sol , not working here somehow
class Solution {
public:
    
    void dfs(Node* head , Node* node , vector<Node*> &vis){
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




*/




class Solution {
public:
    Node* createNode(Node *originalNode , vector<Node*>&nodes) {
        //if we already created that node , nayi node bana rhee kuki ye phle kbi nhi banni thii
        if(!nodes[originalNode->val]){
            nodes[originalNode->val]= new Node(originalNode->val);
        }
        
        //adding neighbors , ab to nayi node bnni..uske neghbour add krdenge...agr nhi bane honge to bana ke nhi toh direct
        for(auto n:originalNode->neighbors){
            //checking if neighbors exist otherwise we create it
            if (!nodes[n->val]) nodes[n->val] = createNode(n,nodes);

            nodes[originalNode->val]->neighbors.push_back(nodes[n->val]);
            
        }
        return nodes[originalNode->val];
    }
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        vector<Node*> nodes(101 , 0);
        nodes[1] = createNode(node,nodes);
        return nodes[1];
    }
};

