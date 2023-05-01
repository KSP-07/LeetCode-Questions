//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
          #define mod 1000000007
        
    long long add(int a , int b){
        return ((a%mod) + (b%mod))%mod; 
    }
    
    long long mul (int a , int b){
        return ( (a%mod)*1LL*(b%mod) )%mod;
    }
    
    long long solve(int n , int k , vector<long long> &dp ){
        
        if(n == 1)
        return k; 
        
        if(n == 2)
        return add(k , mul(k, k-1));
        
        if(dp[n] != -1)
        return dp[n] ; 
        
        
        return dp[n] =  add( (mul(solve(n-2 , k , dp) , k-1)) , (mul(solve(n-1 , k , dp) , k-1)) );
        
        
    }
    long long countWays(int n, int k){
        // code here
        // vector<long long>dp(n+1 , -1);
        vector<long long>dp(n+1 , 0);
        // return solve(n,  k , dp);
        
        dp[0]=0;
        dp[1] = k;
        dp[2] = k*k;
        
        for(int i = 3 ; i<=n ; i++){
            dp[i] = ( (k-1)*dp[i-1] + dp[i-2]*(k-1) )%mod;
        }
        
        return dp[n];
    }

};


//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends