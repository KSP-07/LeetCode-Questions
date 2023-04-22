class Solution {
public:
    int solve(int i , int j , int n , int m, string &s, string &rs , vector<vector<int>> &dp){
        if(i>=n || j>=m) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i]==rs[j]){
            dp[i][j] = 1 + (solve(i+1 ,j+1 , n, m ,s , rs, dp));
        }
        else{
            dp[i][j] = max(solve(i+1 , j , n ,m ,s, rs ,dp) , solve(i , j+1 , n, m , s, rs , dp));
        }
        return dp[i][j];
    }
    int minInsertions(string s) {
        int n = s.size();
        string rev_s = s;
        reverse(rev_s.begin() , rev_s.end());
        // cout<<s<<" "<<rev_s<<endl;                     
        vector<vector<int>> dp(n+1 , vector<int> (n+1 ,-1));
        int len = solve(0,0,n , n , s, rev_s , dp);

        // cout<<len<<endl;
        return n - len;
    }
};