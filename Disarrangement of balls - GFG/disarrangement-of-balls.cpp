//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int mod = 1e9+7;
    long int solve(int N , vector<long int> &dp){
        if(N == 1) return 0;
        if(N==2 ) return 1;
        
        if(dp[N] != -1 ) return dp[N];
        return dp[N] = ((N-1)% mod)* (solve(N-1 , dp)%mod+ solve(N-2 , dp)%mod)%mod;
    }
    long int disarrange(int N){
        // code here
        
        // vector<long int> dp(N +1, -1);    //N+1 isliye lia kuki N tkk ki index pe store kr rhaa ans
        vector<long int> dp(N+1 , 0);
        // return solve(N , dp)%mod;
        
        dp[2] = 1;
        for(int i = 3 ; i<=N ; i++){
            dp[i] = (i-1)%mod *(dp[i-1]%mod + dp[i-2]%mod)%mod;
        }
        
        return dp[N];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends