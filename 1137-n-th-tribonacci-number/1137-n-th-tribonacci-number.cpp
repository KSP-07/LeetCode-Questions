class Solution {
public:
    int tribonacci(int n) {
        if(n == 0 ) return 0 ;
        // if ( n <= 2 ) return 1; //already handled in loop
        
        int T0 = 0 ;
        int T1 = 1 ;
        int T2 = 1 ;
        
        int Tn = 1 ; 
        for(int i = 3 ; i <= n ; i++ ) {
            Tn = T0 + T1 + T2 ; 
            T0 = T1 ; 
            T1 = T2 ;
            T2 = Tn ; 
        }
        return Tn ; 
    }
};