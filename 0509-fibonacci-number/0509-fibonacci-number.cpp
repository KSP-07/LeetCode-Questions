class Solution {
public:
    /*
    int solve ( int n ) {
        if( n <= 1 ) return n ; 
        
        return solve( n-1 ) + solve ( n - 2 ) ;
    }
    */
    int fib(int n) {
        if( n <= 1 ) return n ; 
        
        // return solve ( n ) ;
        
        /*
        vector<int> dp ( n+1 ) ;
        
        dp[0] = 0 ;
        dp[1] = 1;
        
        for(int i = 2 ; i <= n ; i++ ) {
            dp [ i ] = dp [ i -1 ] + dp[ i - 2 ] ;
        }
        
        return dp[n];
        */
        
        int var1 = 0 , var2 = 1 ;
        int ans = 1 ;
        
        for( int i = 2 ; i <= n ; i++ ) {
            ans = var1 + var2 ;
            var1 = var2 ;
            var2 = ans ;            
        }
        
        return ans ;
    }
};