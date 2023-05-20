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
        
        vector<long int> dp(N +1, -1);    //N+1 isliye lia kuki N tkk ki index pe store kr rhaa ans
        return solve(N , dp)%mod;
        
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