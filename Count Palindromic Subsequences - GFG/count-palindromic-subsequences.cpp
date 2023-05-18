//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    int mod = 1e9+7;
    long long solve(string &str, int i , int j , vector<vector<long long >> &dp){
        if(i==j) return 1;
        if(i>j) return 0;
        if(dp[i][j] !=-1) return dp[i][j];
        
        if(str[i] == str[j]){
            return dp[i][j] = ((solve(str , i , j-1,dp)%mod + solve(str , i+1,j , dp)%mod + 1 ) %mod)%mod;
        }
        else{
            return dp[i][j] =(( solve(str , i , j-1 , dp)%mod + solve(str , i+1 , j , dp)%mod - solve(str, i+1 , j-1 , dp)%mod +mod) %mod)%mod;
        }
    }
    long long int  countPS(string str)
    {
       //Your code here
       int n = str.size() ;
    //   string temp = str;
    //   reverse(temp.begin() , temp.end());

       vector<vector<long long>> dp(n+1,vector<long long > (n+1 ,-1));
       int i = 0 , j = n-1;
       return solve(str,i ,j  , dp)%mod;
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends