//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int solve( string &s , string &t , int n , int m, vector<vector<int>> &dp){
      if( n <= 0 ) return m;
      if(m <=0) return n;
      
      if( dp[n][m] != -1) return dp[n][m];
      
      if(s[n-1] == t[m-1]){
          return dp[n][m] = 0 + solve(s , t , n-1 , m-1 , dp);
      }
      return dp[n][m] = 1 + min(solve(s , t,  n , m-1 , dp) /*insert op*/, 
      min(solve( s, t , n-1 , m-1 , dp)  /*replace op*/, solve( s, t , n-1 , m , dp) ) /*del op*/);
  
  }
  
    int editDistance(string s, string t) {
        // Code here
        int n = s.size() ;
        int m = t.size() ;
        
        // vector<vector<int>> dp(n+1 , vector<int> (m+1 , -1));
        
        vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0));
        // return solve(s , t , n , m , dp); 
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j <= m ; j++){
                // if(i==0) dp[i][j] = j;
                // if(j==0) dp[i][j] = i;
                
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min ( dp[i-1][j-1] , min (dp[i][j-1] , dp[i-1][j]));
                }
            }
        }
        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends