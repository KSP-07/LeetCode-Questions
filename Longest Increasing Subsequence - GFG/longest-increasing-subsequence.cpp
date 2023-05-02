//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int solve( int i , int n , int a[] , int last ,vector<vector<int>> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i][last+1] != -1) return dp[i][last+1] ;
        
        int take = 0 , nottake = 0;
        if(last == -1 || a[i]>a[last]){
            // int newL = a[i];
            take =  1 + solve(i+1 , n , a , i , dp);
        }
        nottake = 0+solve(i+1 , n , a, last , dp);
        
        return dp[i][last +1 ] = max(take , nottake);
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n , vector<int>(n+1 , -1));
       return solve( 0 , n , a , -1 , dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends