class Solution {
public:
    int bfs(int i , int j , vector<vector<int>>& grid , int n ,int m){
        
                
        queue<pair<int,int>> q;
        
        q.push({i,j});
        grid[i][j]=0;   //visited array ki jrurat na pdde isliye
        int res=1;  //ek push krdia na q mai kmse kam
        
         vector<pair<int,int>> move = {{0,-1} , { 0,1} , {1,0} , {-1,0}};  //possible movements

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto it: move){
                int nrow = it.first + row;
                int ncol = it.second + col;
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                    grid[nrow][ncol] = 0;
                    q.push({nrow , ncol});
                    res+=1;  //yaha aane ka mtlb hii yhii hai ki ek aur milgyaa
                }
            }
        }
        return res;
    }
    
    //ith loc of 1 se bfs call krdenge....mutliple bfs call hongi kuki ek ek jagah se suru hoke toh khtm hii hojaygii pura q 
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m ,0));

         int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp=0;
                if(grid[i][j]==1) temp=bfs(i , j , grid,n,m);
                maxi= max(temp ,maxi);
            }
        }
              
        return maxi;
    }
};