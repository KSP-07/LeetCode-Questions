class Solution {
public:
    int solve( int i , int j , int n , vector<vector<int>> &triangle , vector<vector<int>> &dp){
        if(i<0 || i>=n || j<0 || j>=triangle[i].size() ) return INT_MAX ;
        
        if(i == n-1 ){
            return triangle[i][j] ; 
        }
        
        if(dp[i][j] != -1) return dp[i][j] ;
        

        int down = solve( i+1 , j , n , triangle  ,dp ) ;
        int right = solve(i+1 , j+1 , n , triangle  ,dp ) ;
        
        int best = min (down , right);
        // cout<<triangle[i][j] + best<<" "<<triangle[i][j] <<" "<< best<<endl;
        
        return dp[i][j] = triangle[i][j] + best ;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n  = triangle.size();
        
        vector<vector<int>> dp(n , vector<int> (n , -1));
        // dp[0].push_back(triangle[0][0]);
        
        return solve(0,0 , n , triangle , dp) ;
    }
};