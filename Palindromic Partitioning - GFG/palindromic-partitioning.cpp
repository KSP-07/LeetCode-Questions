//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool isPalindrome(string &s, int i,int j){
       if(i==j)return 1;
      while(i<j){
          if(s[i]!=s[j])return false;
          i++,j--;
      }
      return true;
    }
    
    int solve(int i, int n , string &str , vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!= -1) return dp[i];
        // if(isPalindrome(str , i , j)) return 0;
        
        int minCost = 1e9;
        for(int j = i ; j<n ;j++){
            if(isPalindrome(str , i , j)){
                int cost = 1 + solve(j+1 , n , str , dp);
                minCost = min(minCost , cost);
            }
        }
        
        return dp[i] = minCost;
    }
    
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size() ;
        // if(isPalindrome(str ,0 , n)) return 0;
        // dp.resize(n ,-1);
        vector<int> dp(n,-1);
        
        return solve(0 , n , str , dp) -1 ;
        
    }
};



// User function Template for C++

// class Solution{
// public:
    
//     vector<vector<int>> dp;
    
//     bool isPalindrome(string s, int i,int j){
//         for(int p=i,q=j;p<=q;p++,q--){
//             if(s[p]!=s[q]) return false;
//         }
//         return true;
//     }
//     int mpp(string s ,int i ,int j){
//         if(i>=j){
//             return 0;
//         }
//         if(isPalindrome(s,i,j)==true){
//             return 0;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         int ans=INT_MAX;
//         for(int k=i; k<j ; k++){
//             int temp=  (dp[i][k]!=-1 ? dp[i][k] : mpp(s,i,k) )
//             + (dp[k+1][j]!=-1 ? dp[k+1][j] : mpp(s,k+1 , j)) + 1;
            
//             ans=min(ans,temp);
//         }
//         dp[i][j]=ans;
//         return ans;
//     }
//     int palindromicPartition(string str)
//     {
//         // code here
//         int len=str.size();
//         dp.resize(len+1, vector<int> ( len + 1 , -1));
//         return mpp(str ,0,len-1);
//     }
// };

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends