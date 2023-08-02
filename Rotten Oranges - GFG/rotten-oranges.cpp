//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        //creating a visited array
        vector<vector<int>> vis(n , vector<int> ( m , 0)) ;
        
        //queue for BFS
        queue<pair<pair<int,int> , int>> q;
        
        for(int i = 0 ; i < n ; i++ ) {
            for (int j = 0 ; j < m ; j++ ) {
                if(grid[i][j] == 2){
                    q.push({{i,j} , 0});
                    vis[i][j] = 2;   //2 isliye kr rhee kuki check kr sake aage ki koi fresh reh toh nhi gaya
                }
            }
        }
        
        vector<pair<int,int>> moves = { {-1,0}  , {1,0} , {0,-1} , {0 , 1}};
        int max_time = 0;
        while(!q.empty()){
            auto it = q.front() ; q.pop() ;
            
            int i = it.first.first;
            int j = it.first.second;
            int time = it.second ;
            
            max_time = max(max_time , time) ;
            
            for( auto k : moves){
                int new_i = i + k.first;
                int new_j = j + k.second;
                
                if( new_i >=0 && new_i <n && new_j >=0 && new_j < m && vis[new_i][new_j] ==0 && grid[new_i][new_j] == 1){
                    q.push({{new_i ,new_j} , time+1});
                    vis[new_i][new_j] = 2;
                }
            }
            
            
        }
        
        for(int i = 0 ; i < n ; i++ ) {
            for (int j = 0 ; j < m ; j++ ) {
                if(vis[i][j] != 2 && grid[i][j] == 1 ){
                   return -1;
                }
            }
        }
        return max_time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends