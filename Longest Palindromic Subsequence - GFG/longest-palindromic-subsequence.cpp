//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  bool isPalindrome( string &s , int i , int j ){
      while( i < j ) {
          if(s[i] != s[j] ) return false;
          
          i++;
          j--;
      }
      return true;
  }
  
  int solve(string &str , vector<vector<int>> &dp , int i , int j ) {
      if( i > j ) return 0 ;
      
      if(dp[i][j] != -1 ) return dp[i][j] ;
      
      if(isPalindrome(str , i , j )){
          return dp[i][j] = ( j - i + 1 ) ; 
      }
      
      int nopick = 0 , pick = 0 ;
      
      if(str[i] == str[j]){
          pick = 2 + solve(str , dp , i+1 , j-1 ) ;
      }
      
      nopick = max( solve(str , dp , i+1 , j) , solve(str , dp , i , j-1));
      
      return dp[i][j] = max(pick , nopick ) ;
      
  }
    int longestPalinSubseq(string A) {
        //code here
        int n = A.size() ;
        vector<vector<int>> dp (n , vector<int> (n , -1)) ;
        
        return solve(A , dp , 0 , n-1);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends