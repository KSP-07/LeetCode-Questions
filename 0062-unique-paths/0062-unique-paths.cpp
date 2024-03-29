class Solution {
public:
    int dfs(int i , int j , int m , int n , vector<vector<int>> &dp){
        if(i>m || i<0 || j>n || j<0) return 0 ;
        
        if(i == m && j == n ) return 1 ;
        
        if( dp[i][j] != -1 ) return dp[i][j] ;
        
        return dp[i][j] = (dfs( i +1 ,j , m , n , dp) + dfs(i , j+1 , m , n , dp)) ;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp( m , vector<int> (n , -1)) ;
        
        return dfs(0 , 0 , m-1 , n-1 , dp ) ;
    }
};