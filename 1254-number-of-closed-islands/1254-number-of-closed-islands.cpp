class Solution {
public:
    bool isValid(int nx ,int ny , int n ,int m ,vector<vector<int>> &grid){
        if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0) return true;
        return false;
    }
    void dfs(int i ,int j , int n ,int m ,vector<vector<int>> &grid){
        grid[i][j] =1;
        vector<pair<int,int>> move = {{0 , 1} , {1,0} , {-1,0} ,{0,-1}};
        // for(auto i)
        for(auto it : move){
            int nx = it.first + i;
            int ny = it.second + j;

            if(isValid(nx ,ny , n , m , grid)){
                dfs(nx, ny , n,m , grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> vis(n , vector<int>(m , 0));
        //boundry dfs
        for(int i =0; i<n ;i++){
            for(int j =0; j<m ;j++){
                if(i*j == 0 || i==n-1 || j == m-1){
                    if(grid[i][j] == 0){
                        dfs(i,j ,n ,m , grid);
                    }
                }
            }
        }
        
        //call dfs in whole grid to count the islands
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    cnt++;
                    dfs(i ,j ,n ,m ,grid);
                }
            }
        }
        return cnt;
    }
};