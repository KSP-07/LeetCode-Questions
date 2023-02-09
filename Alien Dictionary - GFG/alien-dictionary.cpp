//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    vector<int> topoS(int V , vector<int> adj[]){
        //finding indegree 
        vector<int> in(V, 0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                in[it]++;
            }
        }
        
        //queue mai push krenge jiski indegee 0 hai
        queue<int> q;
        for(int i=0;i<V;i++){
            if(in[i]==0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            for(auto it: adj[node]){
                in[it]--;
                if(in[it]==0) q.push(it);
            }
        }
        return ans;
    }
    public:
    
    //can be done using topo sort
    string findOrder(string dict[], int n, int K) {
        //code here
        
        //first we will create a graph , graph is created usign array or list as adjancey matrix or list
        vector<int> adj[K];
        
        //ab first word or second word ko leke compare krenge ki phla distant char kaun hai
        //kuki , jo distant hoga aur phle aayga wo dusre pe apni edge dalega
        for(int i=0;i<n-1;i++){
            string s1= dict[i];
            string s2=dict[i+1];
            int ln= min ( s1.size() ,s2.size());
            for(int j=0;j<ln;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back( s2[j]-'a');    //s1 aur s2 jab diff aay toh phle diff char pe push back krre..toh edge pddri dusre pe
                    break;
                }
            }
        }
        
        vector<int> topo = topoS(K , adj);
        
        //ab topo sort mai store hogya toh bss ans string mai conver kr rhee
        string ans="";
        for(auto it: topo){
            ans+=char( it + 'a');
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends