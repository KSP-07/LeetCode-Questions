class Solution {
public:
    int dfs(int i , int j , vector<vector<int>> &Grid , int m, int n , vector<vector<int>> &dp ) {
        
        if(i>=m || i<0 || j<0 || j>=n || Grid[i][j]==1) return 0;
        
        if( i==m-1 && j == n-1 ) return 1 ;
        
        if(dp[i][j] != -1 ) return dp[i][j] ;
        
        return dp[i][j] = dfs(i+1 , j , Grid , m , n , dp ) + dfs(i , j+1 , Grid , m ,n , dp) ;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m = Grid.size() ;
        int n = Grid[0].size() ;
        
        vector<vector<int>> dp(m , vector<int> (n , -1)) ;
        
        return dfs(0 , 0 , Grid , m , n , dp);
    }
};