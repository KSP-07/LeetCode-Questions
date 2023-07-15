class Solution {
public:
    int solve ( vector<int> &prices , int i , int B , int n , int limit , int k , vector <vector < vector<int> > > &dp ) {
        if( i == n ) return 0 ;
        
        if ( limit == k ) return 0 ;
        
        if( dp[i][B][limit] != -1 ) return dp[i][B][limit] ;
        
        int profit = 0 ;
        if( !B) {
            int buy = -prices[i] + solve ( prices , i+1 , 1 , n , limit , k , dp ) ;
            int skip = solve (prices , i + 1 , 0 , n , limit , k , dp ) ;
            
            profit = max(buy ,skip) ;
        }
        else {
            int sell = prices[i] + solve( prices , i+1 , 0 , n , limit +1 , k , dp );
            int skip = solve ( prices , i+1 , 1 , n , limit , k , dp ) ;
            
            profit = max( sell , skip ) ;
        }
        
        return dp[i][B][limit] = profit ;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ;
        
        vector <vector < vector<int> > > dp(n , vector<vector<int>> (2 , vector<int> ( k+1 , -1 ))) ;
        
        return solve ( prices , 0 , 0 , n , 0, k , dp ) ; 
    }
};