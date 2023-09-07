//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	int solve(string &str1 , string &str2 , int n , int m , vector<vector<int>> &dp){
	    if( n == 0 || m == 0 ) return 0 ;
	    
	    if(dp[n][m] != -1 ) return dp[n][m] ;
	    
	    int pick = 0 , nopick = 0; 
	    if(str1[n-1] == str2[m-1] && n != m ){
	        pick = 1 + solve(str1 , str2 , n-1 , m-1 , dp);
	    }
	    nopick = max(solve(str1 , str2 ,n-1 , m , dp) , solve(str1 , str2 , n, m-1 , dp)) ;
	    
	    return dp[n][m] = max(pick , nopick) ;
	}
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    vector<vector<int>> dp( n+1 , vector<int> (n+1 , -1)) ;
		    
		    return solve(str , str ,n , n , dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends