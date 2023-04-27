//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
    public:
    int mod =1000000007;
    int permutationCoeff(int n, int k){
        //Code here
        
        // long long dp[n+1]={0};
        // dp[0]=1;
        // // dp[1] =1;
        
        // for(int i = 1 ; i<=n;i++){
        //     dp[i] = i * dp[i-1];
        // } 
        // // cout<<i<<dp[k];
        // return (dp[n] / dp[n-k])%mod;
        
        long long P = 1;
     
        // Compute n*(n-1)*(n-2)....(n-k+1)
        for (int i = n; i > (n-k); i--)
            P =  (P * i)%mod ;
     
        return P;
    }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        Solution ob;
        int ans = ob.permutationCoeff(n,k);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends