//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int mod = 1e9+7 ;
    long long solve(string &str , int i , int j , vector<vector<int>> &dp){
        if( i== j ) return 1 ;
        if( i > j ) return 0 ;
        
        if(dp[i][j] != -1 ) return dp[i][j] ;
        
        long long count = 0 ;
        if(str[i] == str[j] ){
            count +=(1+ solve(str , i+1 , j-1 , dp))%mod;
        }
        count += ( solve(str , i+1 , j , dp)%mod + solve(str , i , j-1 , dp)%mod - solve(str, i+1 , j-1 , dp)%mod  + mod)%mod;
        
        return dp[i][j] = count;
        
    }
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       int n = str.size() ;
       
       vector<vector<int>> dp(n , vector<int> (n , -1)) ;
       return solve(str , 0 , n-1 , dp ) ;
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