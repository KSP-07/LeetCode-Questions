//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
//   long long solve(int coins[]  , int n , int sum , vector<vector<long long>> &dp){
//       if(sum==0){
//           return 1;
//       }
//       if(n==0){
//         //   dp[n]
//           return 0;
//       }
//       if(dp[n][sum]!=-1) return dp[n][sum];
      
//       if(coins[n-1]<=sum){
//           return dp[n][sum] = solve(coins , n-1 , sum , dp) + solve(coins,n , sum-coins[n-1] , dp);
//       }
//       else return dp[n][sum] = solve(coins , n-1 , sum , dp);
//   }
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long>> dp(N+1 , vector<long long> (sum+1 ,0));
        int m = sum+1;
        //  for(int i=0,j=0;i<m;i++) dp[j][i]=0;
        // for(int i=0,j=0;i<N+1;i++) dp[i][j]=1;
       for(int t=0;t<=sum;t++)
        {
            dp[0][t]=(t%coins[0]==0);
        }
        for(int ind=1;ind<N;ind++)
        {
            for(int t=0;t<=sum;t++)
            {
                long long int notTake=dp[ind-1][t];
                long long int take=0;
                if(coins[ind]<=t)
                {
                    take=dp[ind][t-coins[ind]];
                }
                dp[ind][t]=take+notTake;
            }
        }
        return dp[N-1][sum];
        
        // return solve(coins , N, sum , dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends