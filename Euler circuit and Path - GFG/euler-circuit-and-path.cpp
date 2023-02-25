//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isEularCircuit(int V, vector<int>adj[]){
	    // Code here
	    int oddVertices =0;
	    
	    //for ex..1 ke node hai toh adj[i]=2 , pe uske neighbours uske indegree ho jayge na undirected graph mai
	    for(int i=0;i<V;i++){
	        if(adj[i].size()%2 != 0) oddVertices++;
	    }
	    
	    if(oddVertices==0) return 2;  //circuit
	    else if(oddVertices == 2) return 1;  //path
	    else return 0;  //graph is not euler
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEularCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends