//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        if(N==1) return Matrix[0][0];
        vector<vector<int>> dp(N, vector<int> (N));
        dp = Matrix;
        int max_sum = 0;
        for(int i = N-2 ; i>=0 ; i--){
            for(int j = N-1 ; j>=0 ;j--){
                dp[i][j] = Matrix[i][j] + max(dp[i+1][j] , max(dp[i+1][j-1] , j+1==N? 0 :dp[i+1][j+1]));
                max_sum = max(max_sum, dp[i][j]);
            }
        }
        return max_sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends