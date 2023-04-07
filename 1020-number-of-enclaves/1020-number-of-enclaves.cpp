class Solution {
public:
    bool isValid(int x , int y , int n , int m , vector<vector<int>> &grid ){
        if( x>=0 && x<n && y>=0 && y<m && grid[x][y]==1) return 1;
        return 0;
    }
    void dfs(int x , int y , int n , int m , vector<vector<int>> &grid){
        grid[x][y] = 0;
        vector<pair<int, int >> move = {{0,1} , {1,0} , {-1,0} , { 0 , -1}};
        
        for(auto i : move){
            int nx = x + i.first;
            int ny = y + i.second;
            
            if(isValid(nx , ny , n , m , grid)){
                dfs(nx , ny , n , m, grid);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
    //calling dfs to remove 1's from boundry so can easily count 1's inside 
        for(int i=0; i< n; i++){
            for(int j = 0 ; j < m ; j++){
                if(i*j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1) dfs(i , j , n , m , grid );
                }
            }
        }
        
        //count 1's inside
        int ans=0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j< m ; j++){
                if( grid[i][j] == 1){
                   ans++;
                }
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
        return ans;
        
    }
};