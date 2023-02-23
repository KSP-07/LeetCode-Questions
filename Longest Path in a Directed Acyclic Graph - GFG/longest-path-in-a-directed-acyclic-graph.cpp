//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    void dfs(int node , vector<pair<int,int>>adj[] , vector<int> &vis , stack<int> &s){
        vis[node]=1;
        for(auto i: adj[node]){
            if(!vis[i.first]) dfs(i.first , adj , vis , s);
        }
        s.push(node);
    }
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
            // code here
            
            vector<pair<int,int>> adj[v];
            for(int i=0;i<e; i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
                
                adj[u].push_back({v , wt});
            }
            
            //topological sort 
            stack<int> s;
            vector<int> vis(v , 0);
            for(int i=0;i<v ;i++){
                if(!vis[i]){
                    dfs(i , adj , vis , s);
                }
            }
            
            vector<int> dist (v, INT_MIN);
            dist[src]=0;
            
            while(!s.empty()){
                auto node = s.top();
                s.pop();
                
                for(auto i: adj[node]){
                    int newNode = i.first ;
                    int wt = i.second;
                    
                    if(dist[node]==INT_MIN) continue;  //this node has to be visited first then only path can go through it
                    
                    if(dist[node] + wt > dist[newNode]){
                        dist[newNode] = dist[node] + wt;
                    }
                }
                
            }
            return dist;
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends