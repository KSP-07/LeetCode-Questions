//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> dp;
    
    int solve(int i , int j , int freq[]){
        if(i>j) return 0;
        
        if(dp[i][j] != 1e9) return dp[i][j];
        
        int sum = accumulate(freq+i , freq+j+1 , 0);
        
        for(int k = i ; k<=j ; k++){
            dp[i][j] = min(dp[i][j] , sum + solve(i , k-1 , freq) + solve(k+1 , j , freq));
        }
        
        return dp[i][j];
    }
    
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // code here
        dp.resize(n , vector<int> (n , 1e9));
        
        return solve(0 , n-1 , freq);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends