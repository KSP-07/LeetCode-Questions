class Solution {
public:
    
    int solve ( vector<int> &prices , int i , int B , int lock , int n , vector<vector<vector<int>>> &dp ) {
        
        if ( i == n ) return 0 ;
        if(dp[i][B][lock] != -1 ) return dp[i][B][lock] ;
        if (lock) return dp[i][B][lock] = solve ( prices , i+1 , B, !lock , n , dp );
        
        int profit = 0 ;
        if(!B) {
            int buy = -prices[i] + solve(prices, i+1 , 1 , lock , n , dp ) ;
            int skip = solve (prices , i+1 , 0 , lock , n , dp ) ;
            
            profit = max ( buy , skip) ;
            
        }
        else {
            int sell = prices[i] + solve (prices , i+1 , 0 , 1 , n , dp ) ;
            int skip = solve( prices , i+1 , 1 , 0 , n , dp ) ;
            
            profit = max (sell , skip ) ;
        }
        return dp[i][B][lock] = profit ;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        
        vector<vector<vector<int>>> dp ( n , vector<vector<int>> (2 , vector<int> (2 , -1 ))) ;
        
        return solve (prices , 0 , 0 , 0 , n , dp );
    }
};