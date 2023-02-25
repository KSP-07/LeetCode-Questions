//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dijkstra(vector<pair<int,int>> adj[] , int S , int dst , int n){
       vector<int> vis(n,false);
            vector<int> dist(n,1e8);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,S});
            dist[S]=0;
            while(!pq.empty()){
                pair<int,int> p=pq.top();
                pq.pop();
                int u=p.second;
                if(vis[u]){continue;}
                vis[u]=true;
                for(auto x : adj[u]){
                    int v=x.first,e=x.second;
                    if(!vis[v] && dist[v] > e+dist[u]){
                        dist[v]=e+dist[u];
                        pq.push({dist[v],v});
                    }
                }
            }
        return dist[dst];
    }
    
    //if there is already en edge then we give wt as 0 , otherwise create an edge with wt 1 , then use dijkstra's for shortest path
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            vector<pair<int ,int>> adj[n];
            

            for(auto i:edges){
                int u = i[0] -1;
                int v = i[1]-1;
                adj[u].push_back({v ,0});
                adj[v].push_back({u , 1});
            }
            
            int ans = dijkstra(adj , src-1, dst-1 , n);
            if(ans==1e8) return -1;
            return ans;
            
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(m,vector<int> (2));
        for(auto &j:edges)
            for(auto &i:j)
                cin>>i;
        int src,dst;
        cin>>src>>dst;
        Solution s;
        cout<<s.minimumEdgeReversal(edges,n,src,dst)<<endl;
    }
    return 0;
}
// } Driver Code Ends