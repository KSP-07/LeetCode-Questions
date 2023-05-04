//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(int arr[] , int i ,int n , int last , vector<vector<int>> &dp){
	    if(i==n) return 0;
	    
	    if(dp[i][last + 1] != -1) return dp[i][last+1];
	    int pick = 0 ;
	    if(last==-1 || arr[last] < arr[i]){
	        pick = arr[i] + solve(arr , i+1 , n , i, dp );
	    }
	    int noPick = solve(arr , i+1 , n , last, dp );
	    
	    return dp[i][last+1] = max(pick, noPick);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	   // vector<vector<int>> dp (n , vector<int> (n+1 , -1));
	   // return solve(arr ,0 , n ,-1 ,dp);
	   
	   vector<int> currRow(n+1 , 0);
	   vector<int> nextRow(n+1 , 0);
	   
	   for(int i = n-1 ; i>=0 ;i--){
	       for(int j = i-1 ; j>=-1 ; j--){
	           int take = 0;
	           if(j==-1 || arr[j] < arr[i]){
	               take  = arr[i] + nextRow[i+1];
	           }
	           int nopick = nextRow[j+1];
	           
	           currRow[j+1] = max(take , nopick);
	           
	           nextRow = currRow;
	       }
	   }
	   return nextRow[0];
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends