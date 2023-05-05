// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    vector<vector<int>> dp;
    int func(int e , int f){
        if(f==0 || f==1){
            return f;
        }
        if(e==1){
            return f;
        }
        if(dp[e][f]!=-1){
            return dp[e][f];
        }
        int ans=INT_MAX;
        for(int k=1 ; k<=f;k++){
            int temp= 1 + max(dp[e-1][k-1]==-1?func(e-1 , k-1):dp[e-1][k-1] 
            , dp[e][f-k]==-1?func(e , f-k) : dp[e][f-k]);
            
            ans=min(ans , temp);
        }
        return dp[e][f]=ans;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        dp.resize(n+1 , vector<int>(k+1 , -1));
        return func(n , k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends