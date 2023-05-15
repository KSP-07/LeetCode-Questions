//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	
	long long solve(int N , vector<long long> &dp){
	    if(N <= 1) return 1;
	    if(dp[N] !=-1) return dp[N];
	    
	    long long ans = 0 ;
	    for(long long i = 0 ; i < N ; i++ ){
	        ans = (ans + solve(i , dp) * solve(N - i -1 , dp ))%mod;
	    }
	    
	    return dp[N] = ans;
	}
	
	int prefixStrings(int N)
	{
	    // Your code goes here
	    vector<long long> dp(N+1 , -1);
	    return solve(N , dp);
	}

};
	

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n;
       	cin >> n;

       

        Solution ob;
        cout << ob.prefixStrings(n);
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends