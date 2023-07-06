class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex + 1 ;  // bcoz of 0 indexing
        
        vector<int> res;
        long long ans = 1 ; 
        res.push_back ( ans ) ;
        
        for ( int j = 1 ; j < n ; j++ ) {
            ans = ans * (n - j );
            ans = ans / j ;
            
            res.push_back( ans ) ;
        }
        return res ;
    }
};