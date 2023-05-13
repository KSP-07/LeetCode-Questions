//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod = 1e9+7;
    long long int countBT(int h) { 
        // code here
        /*
        long long int dp[h+1];
        
        dp[0] = dp[1] = 1;
        
        for(int i = 2 ; i <= h ; i++){
            dp[i] = (dp[i-1] * ((2 * dp[i-2])%mod  +  dp[i-1])%mod) %mod;
        }
        return dp[h];
        */
        
        long long int dp0 = 1 , dp1 = 1 , dp2;
        for(int i =2 ; i<= h ;i++){
            dp2 = (dp1 * ((2*dp0)%mod + dp1)%mod)%mod;
            
            dp0 = dp1;
            dp1 = dp2;
        }
        return dp2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends