class Solution {
public:
  
    string longestPalindrome(string S) {

        int n = S.size(), maxLen=1, start=0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        // for(int i = 0 ; i < n ; i++) dp[i][i] = true;
        for(int gap = 0; gap < n ; gap++){    
            for(int i=0 , j = gap ; j < n ; i++ , j++ ){
                
                if( gap == 0) dp[i][j] = true;
                else if ( gap == 1){
                    if(S[i] == S[j] ) dp[i][j] = true;
                    else dp[i][j] = false ;
                }
                else{
                    if(S[i] == S[j] && dp[i+1][j-1]) dp[i][j] = true;   //idr check kr rhe ki end ke same and aur fir ha toh unke bich ke same hai ya nhi
                    else dp[i][j] = false ;
                }
                if(dp[i][j] && gap+1 > maxLen) maxLen = gap+1, start = i;
            }
        }

        return S.substr(start, maxLen);
    }
};