class Solution {
public:
    
    bool match (string &a , string &b ){
        int n1  = a.size() ;
        int n2 = b.size() ;
        
        if( n2 - n1 != 1 ) return false ;
        
        int first = 0 ;
        int second = 0 ;
        
        while ( second < n2 ) {
            if( a[first] == b[second] ){
                first++ ;
                second++ ;
            }
            else second++ ;  // ek se jada diff hua koi toh ye phle end hojayga
        }
        
        if(first == n1 && second == n2 ) return true ;
        return false;
    }
    
    static bool comp(string &a , string &b) {return a.size() < b.size() ; } 
    int longestStrChain(vector<string>& words) {
        
        
        sort(words.begin() , words.end() , comp ) ;
        
        int maxi = 1;
        int n = words.size() ;
        
        vector<int> dp( n , 1 ) ;
        
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int prev = 0 ; prev < i ; prev++ ) {
                if( match( words[prev]  , words[i] )  && 1 + dp[prev] > dp[i] ) {
                    dp[i] = 1 + dp[prev] ;
                }
            }
            maxi = max ( maxi , dp[i] ) ; 
        }
        return maxi ;
    }
};