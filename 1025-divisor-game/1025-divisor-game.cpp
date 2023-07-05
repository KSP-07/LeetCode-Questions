class Solution {
public:
    bool divisorGame(int n) {
        /*
        if( n <= 1 ) return false ;
        
        for ( int i = 1 ; i < n ; i++ ) {
            if( n % i == 0 ) return !divisorGame( n - i ) ; 
        }
        
        return false ; 
        */
        
        if( n % 2 == 0 ) return true ;
        else return false ; 
    }
};