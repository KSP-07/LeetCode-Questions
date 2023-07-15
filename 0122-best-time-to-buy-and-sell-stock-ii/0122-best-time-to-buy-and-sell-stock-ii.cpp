class Solution {
public:
    int f(vector<int> &prices , int i , int n , int B , vector<vector<int>> &dp ) {
        
        if ( i == n) return 0 ;
        if(dp[i][B] != -1 ) return dp[i][B] ;
        int ans = 0 ;
        if ( !B ) {
            ans = max (-prices[i] + f(prices , i , n , 1  , dp) , f(prices , i+1 , n , 0  , dp));
        }
        else{
            ans = max ( prices[i] + f (prices , i+1 , n , 0  , dp) , f(prices , i+1 , n , 1  , dp));
        }
        
        return dp[i][B] = ans ;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size() ;
        
        vector<vector<int>> dp ( n+1 , vector<int> (2 , -1));
        return f(prices, 0 , n , 0 , dp ) ;
    }
};