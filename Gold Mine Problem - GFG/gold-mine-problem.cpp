//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int dfs( int i , int j , int n , int m , vector<vector<int>> &dp , vector<vector<int>> &mine){
        if(i>= n || i<0 || j>=m || j<0 ) return 0;
        
        if(dp[i][j] != -1 ) return dp[i][j];
        
        return dp[i][j] = mine[i][j] +  max(dfs(i+1 , j+1 , n , m , dp , mine) , max(dfs(i , j + 1 , n , m , dp ,mine) , dfs(i-1 , j+1 , n ,m, dp,mine)));
    }
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> dp(n ,vector<int> (m , -1));
        int ans =0;
        for(int i = 0 ; i < n ; i++){
            int temp = dfs(i , 0 , n , m , dp , M);
            ans = max(ans , temp) ;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends