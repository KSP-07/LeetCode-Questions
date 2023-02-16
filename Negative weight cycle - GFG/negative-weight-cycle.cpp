//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> dist(n , 1e8);  //taking distance array , with dist infinity
	    dist[0] =0;   //taking dist of source with src as 0
	    
	    //in bell man ford we have to traverse for n-1 times ,but here traversing one more time to check if still any
	    //distance gets updated , coz if it does after n-1 loops there is -ve cycle
	    for(int i=0;i<n;i++){
	        for(auto it: edges){
	            int u = it[0];  
	            int v = it[1];
	            int wt = it[2];
	            if(dist[u]!= 1e8 && dist[u] + wt < dist[v] ){
	                if(i==n-1) return 1;   //in nth pass still there is dist getting updated means cycle is there
	                dist[v] = dist[u] + wt;
	            }
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends