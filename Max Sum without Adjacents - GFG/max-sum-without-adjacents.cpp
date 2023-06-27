//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

int solve(int *arr ,int i , int n , vector<int> &dp){
    if(i >= n) return 0;
    if(dp[i]!= -1) return dp[i];
    
    return dp[i] = max( arr[i] + solve(arr , i +2 , n , dp) , solve(arr, i+1 , n , dp));
}

	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n ,-1);
	    return solve(arr , 0 , n , dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends