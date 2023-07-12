class Solution {
public:
    int solve( vector<int> &cuts , vector<vector<int>> &dp , int i , int j ) {
        if( j - i <= 1 ) return 0;
        if( dp[i][j] != -1 ) return dp[i][j] ;
        
        int ans = INT_MAX;
        for(int k = i+1 ; k < j ; k++ ) {
            int temp = cuts[j] - cuts[i] + solve(cuts , dp , i , k) + solve(cuts , dp , k , j ) ;
            
            ans = min (ans , temp ) ;
        }
        
        return dp[i][j] = ans ;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0) ;
        cuts.push_back(n) ;
        int m = cuts.size() ;
        
        sort(cuts.begin() , cuts.end()) ;
        vector<vector<int>> dp( m+1 , vector<int> (m+1 , -1)) ;
        return solve ( cuts , dp , 0 , m-1) ;
    }
};