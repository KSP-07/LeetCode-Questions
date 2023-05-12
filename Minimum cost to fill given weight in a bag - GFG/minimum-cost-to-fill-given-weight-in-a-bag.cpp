//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        vector<vector<int>> dp(N+1 , vector<int> (W+1 , -1));
        
        for(int i = 0; i<= N ; i++){
            for(int j = 0 ; j<=W ; j++){
                
                if(i==0 && j == 0 ){
                    dp[i][j] = 0;
                    continue;
                }
                
                if(i==0) {
                    dp[i][j] = 1e9;
                    continue;
                }
                
                if(i<=j && cost[i-1] != -1 ){
                    int a = cost[i-1] + dp[i][j-i];
                    int b = dp[i-1][j];
                    dp[i][j] = min(a , b);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[N][W] == 1e9) return -1;
        return dp[N][W];
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends