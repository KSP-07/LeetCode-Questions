class Solution {
public:
    
   /* void solve(string s , string t , int n , int m , int len , bool &flag, int i , int j) {
        if(flag) return ;
        if(len == n ) {
            flag = true ;
            return;
        }
        
        if(i==n || j==m ) return;
        
        if(s[i] == t[j]){
            solve(s , t, n , m , len +1 , flag , i+1 , j+1);
        }
        
        solve(s , t, n, m , len , flag , i+1 ,j);
        solve(s , t, n ,m ,len , flag , i , j+1);
    }
    */
    bool isSubsequence(string s, string t) {
        int n = s.size() ;
        int m = t.size() ;
        /*
        int len = 0 ;
        bool flag = false ;
        solve(s , t , n , m , len , flag , 0 , 0) ;
        return flag ;
        */
        
        if ( n > m ) return false;
        if(n == 0 ) return true;
        
        for(int i = 0 , j =0 ; i < n && j<m ;j++ ){
            if(s[i] == t[j]) i++ ;
            
            if(i== n ) return true ;
        }
        
        return false;
    }
};