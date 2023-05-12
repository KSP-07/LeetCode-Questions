//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


int count=0;
// vector<vector<int>> dp;
class Solution{
    public:
    // int func(string S1, string S2, int n, int m,int count){
    //     if(n==0 || m==0){
    //         return count;
    //     }
    //     if(dp[n][m]!=-1){
    //         return dp[n][m];
    //     }
    //     else if(S1[n-1]==S2[m-1]){
    //         // func(S1,S2,n-1,m-1);
    //         // return count++;
    //         return count= func(S1,S2,n-1,m-1,count+1);
    //     }
    //     else{
    //         // dp[n-1][m-1]=0;
    //         return count= max(count , max(func(S1,S2,n-1,m,0) , func(S1,S2,n,m-1,0)));
    //     }
    // }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        // dp.resize(n+1,vector<int> (m+1,0));
        // return func(S1,S2,n,m,0);
        int lcs=0;
        int dp[n+1][m+1];
        // for(int i=0;i<1;i++){
        //     for(int j=0;j<1;j++){
        //         dp[i][j]=0;
        //     }
        // }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]= 0;
                }
                else if(S1[i-1]==S2[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];
                    lcs=max(lcs,dp[i][j]);
                }else{
                    dp[i][j]=0;
                }
            }
        }
        return lcs;
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends