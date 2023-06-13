//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long solve(int arr[] , int i , int j , int turn , vector<vector<int>> &dp){
        if(i>j) return 0;
        if(i==j && turn == 0) return arr[i];
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(turn == 0){
            return dp[i][j] = max(arr[i] + solve(arr , i+1 , j , !turn ,dp) , arr[j] + solve(arr , i , j-1 , !turn ,dp));
        }
        else{
            return dp[i][j]= min(solve(arr , i+1 ,j , !turn ,dp) , solve(arr , i , j-1 , !turn  ,dp) );
        }
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<int>> dp(n+1 , vector<int> (n+1 ,-1));
        return solve(arr ,0 , n-1 , 0 ,dp);
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
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends