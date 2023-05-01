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
        vector<long long>dp(n+1 , -1);
        return solve(n,  k , dp);
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