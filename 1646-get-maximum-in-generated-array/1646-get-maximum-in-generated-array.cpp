class Solution {
public:
    int getMaximumGenerated(int n) {
        if( n <= 1) return n ;
        vector<int> ans(n+1);
        ans[0] = 0 ;
        ans[1] = 1 ; 
        /*
        // int maxi = 0;
        for(int i = 1 ; i <= (n/2) ; i++ ) {
            
            ans[2*i] = ans[i] ;
            if(2*i + 1 >n) break;
            ans[2*i + 1 ] = ans[i] + ans[i+1] ;
        }
        
        
        */
        for(int i = 2 ; i <= n ; i++ ) {
            if(i%2 == 0 ) ans[i] = ans[i/2];
            else ans[i] = ans[i/2] + ans[i/2 + 1];
            
        }
        int maxi = *max_element(ans.begin() , ans.end()) ;
        
        return maxi ; 
    }
};