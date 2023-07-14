class Solution {
public:
    bool isPalindrome( string &s , int i , int j){
        // int i = 0 , j = s.size()-1;
        while(i<j){
            if(s[i] != s[j] ) return false ;
            i++; j--;
        }
        return true ;        
    }
    
    int solve ( string &s , int i , int j , vector<vector<int>> &dp ) {
        if(i >= j ) return dp[i][j] = 0;
        
        if(dp[i][j] != -1 ) return dp[i][j];
        
        if ( isPalindrome (s , i , j)) {
            dp[i][j] = 0 ;
            return 0;
        }       
        
        int ans = INT_MAX ;
        int left = 0 , right = 0 ;
        for ( int k = i ; k < j ; k++ ) {
            
            if(isPalindrome(s, i, k)) {    //left is palindromen then
                if(dp[k+1][j] != -1)
                    right = dp[k+1][j];
                
                else {
                    right = solve(s, k+1, j, dp);
                    dp[k+1][j] = right;
                }
            }
            int temp = 1 + right;
            ans = min(ans, temp);
        }
        
        return dp[i][j] = ans ;
    }
    int minCut(string s) {
        int n = s.size() ;
        
        vector<vector< int > > dp ( n , vector<int> (n , -1));
        
        int res = solve ( s , 0 , n-1 , dp );
        return res;
    }
};