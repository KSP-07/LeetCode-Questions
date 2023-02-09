//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //using pq appraoch here
        
        //pq minheap mai wt ko push kraa denge to sbse kam waala hii bhr aayga
        priority_queue<pair<int,int> , vector<pair<int , int>> , greater<pair<int,int>>> q;
        
        //queue wt aur node hii push kr rhee
        q.push({0 , 0});   //starting from zero weight and oth node
        
        //visited array
        vector<int> vis(V ,0);
        int cost =0;
        
        while(!q.empty()){
            int wt = q.top().first;
            int node = q.top().second;
            q.pop();
            //agar node visited nhi hogi phle kabi to hii uske neighbors lenge aur wt , nhi to cycle bann jaygii..to visited wali ko drop hi krdenge
            if(!vis[node]){
                cost+=wt;
                vis[node]=1;
                for(auto it: adj[node]){
                    // for ex oth node ke neigbor visit horhee..toh fir it[1] pe weight aayga aur it[0] pe neighbor node
                    q.push({ it[1] , it[0]});
                }
            }
        }
        return cost;
    }
};
 /* 
 REVIEW IT AS IT IS DONE USING DISJOINT SET
 class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	void makepair(vector<int> &parent,vector<int> &rank , int n)
	{
	    for(int i=0;i<=n;i++)
	    {
	        parent[i] = i;
	        rank[i] = 0;
	    }
	}
	int findparent(vector<int> &parent,int node)
	{
	    if(parent[node] == node)
	    {
	        return node;
	    }
	    return parent[node] = findparent(parent,parent[node]);
	}
	void unionSet(int u,int v,vector<int> &parent,vector<int> &rank)
	{
	     u = findparent(parent,u);
	     v = findparent(parent,v);
	     if(u == v)
	     {
	         return;
	     }
	     
	    if(rank[u]<rank[v])
	    {
	        parent[u] = v;
	    }
	    else if(rank[u]>rank[v])
	    {
	        parent[v] = u;
	    }
	    else
	    {
	        parent[u] = v;
	        rank[v]++;
	    }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> parent(V+1);
        
        vector<int> rank(V+1);
        
        int miniWeight = 0;
        
        makepair(parent,rank,V);
        
       vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                int u = i;
                int v = adj[i][j][0];
                int wt = adj[i][j][1];
                
                edges.push_back({wt,{u,v}});
            }
        }
        sort(edges.begin(),edges.end());
        
        

        for(int i=0;i<edges.size();i++)
        {
            int node1 = edges[i].second.first;
            int node2 = edges[i].second.second;
            int u = findparent(parent,node1);
            int v = findparent(parent,node2);
            int wt = edges[i].first;
                
            if(u != v)
               {
                   miniWeight += wt;
                   unionSet(u,v,parent,rank);
                }
        }
        return miniWeight;
    }
};
*/



//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends