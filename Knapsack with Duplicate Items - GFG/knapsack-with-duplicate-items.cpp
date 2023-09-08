//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int N , int W , int val[] , int wt[] , vector<vector<int>> &dp){
        if(N== 0 || W== 0) return 0 ;
        
        if(dp[N][W] != -1 ) return dp[N][W] ;
        
        int pick = 0 ;
        if(wt[N-1]<= W){
            pick = val[N-1] + solve(N , W-wt[N-1] , val , wt , dp);
        }
        int nopick = solve(N-1 , W , val , wt , dp) ;
        
        return dp[N][W] = max(pick , nopick) ;
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N+1 , vector<int> (W+1 , -1)) ;
        
        return solve(N , W , val , wt , dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends