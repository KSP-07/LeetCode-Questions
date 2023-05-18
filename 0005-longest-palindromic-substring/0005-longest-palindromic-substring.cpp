class Solution {
public:
  
    string longestPalindrome(string S) {
        int n = S.size(), maxLen=1, start=0;
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        for(int k=1; k<n; k++){    //ye kuu
            for(int i=0; i+k<n; i++){
                int j = i + k;
                if(S[i]==S[j]) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = false;
                if(dp[i][j] && j-i+1>maxLen) maxLen = j-i+1, start = i;
            }
        }
        return S.substr(start, maxLen);
    }
};