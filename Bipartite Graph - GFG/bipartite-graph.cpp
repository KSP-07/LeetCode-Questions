//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

//bfs chla ke , neighbour mai opp color store kr rhee , agar color same hotaa hai main node se toh vo bipartitre nhi hai

    bool check(int start , int V , vector<int> adj[] , vector<int> &color){
         queue<int> q;
	    //pushing the starting vertex in queue alongwith marking color in color array
	    q.push(start);
	    color[start]=0;
	    while(!q.empty()){
	        int size = q.size();
	        while(size--){
	            int node = q.front();
	            q.pop();
	            
	            for(auto it : adj[node]){
	                if(color[it]==-1){   //if the adjacent node is not yet colored      
        	            color[it] = !color[node];   //storing opposite color of parent
	                    q.push(it);
	                }
	                //if the adjacent guy having the same color
	                //someone did color it on some other path
	                else if(color[it] == color[node]) return 0;
	            }
	        }
	    }
	    return true;
	    
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    //since there could be differetn componenets , we have to use a loop for each
	    
	    //using color array to keep track of visted and color of nodes
	    vector<int> color(V , -1);
	    
	    //checking for each component
	    for(int i = 0; i < V ; i++){
	        if(color[i]==-1){
	            if(check( i , V , adj , color) == false) return false;
	        }
	    }
	    
	    return true;
	    
	   
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends