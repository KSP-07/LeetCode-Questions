//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int solve(vector<int> &a , int n , vector<int> &dp){
      if(n == -1 ) return 0;
      if (n == 0 ) return a[0]; 
      if (n == 1)  return a[1] + a[0] ;
      if(dp[n] != -1) return dp[n];
      return dp[n] = max( solve(a , n-1 , dp) , max(a[n] + solve(a , n-2 ,dp)  , a[n] + a[n-1] + solve(a ,n-3 , dp) ));
  }
  int findMaxSum(vector<int>& a){
      //Code Here
      int n = a.size();
      vector<int> dp(n  , -1);
      
      return solve(a , n-1 , dp);

  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends