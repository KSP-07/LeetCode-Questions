//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void bfs(int row , int col , vector<vector<char>> &grid , vector<vector<int>> &vis , int n ,int m){
        vis[row][col]=1;  //row aur col milrha jispe '1' aarha thaa..to ab visited mai uss jagah ko..uss row and col pe mark rhe
        
        //bfs traversal ke liye queue use kr rhee
        queue<pair<int , int>> q;
        q.push({row , col});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            //ek point se possibly 8 directions mai traverse kr skte matrix mai , to individually 8 baar likhe ki jagah
            //loops ka use kr rhee
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol = -1 ; delcol <= 1;delcol++){
                    
                    //isme ek kam ek jada hone se possible direction nikal rahe hai
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    
                    //ab ye dekh rhe ki jo nayi pos mili hai wo bounds mai hai ya nhi
                    //nayi pos pe '1' hai ya nhi aur wo nayi pos visied hai ya nhi
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow , ncol});
                    }
                }
            }
        }
        
    }
    
    //ek point lerhe koi bhi suru se jo 1 ho..ab ek one aagya na to cnt++ , aur ab uss point se traversal krlenge koi bhi
    //to pure traversal krne se...related neighbour node mark ho jayge visted..to unpe aake fir cnt nhi bdhega
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        //size lerhe row aur col ka
        int n = grid.size();
        int m = grid[0].size();
        
        //visted array, jo nodes visit horhi unhe mark krne ke liye
        vector<vector<int>> vis(n , vector<int>(m,0));
        int cnt=0;
        
        //grid array mai traverse kr rhe hai , aur jab koi 1 milega jo visited nhi hoga tab action lenge
        for(int row=0; row< n; row++){
            for(int col=0; col<m;col++){
                if(!vis[row][col] && grid[row][col] =='1'){
                    cnt++;
                    bfs(row , col , grid, vis , n , m);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends