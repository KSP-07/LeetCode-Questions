//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//now will use dp with binary search
class Solution
{
    public:
    int longestSubsequence(int n, int a[]){
        if(n==0) return 0;
        
        vector<int> ans;
        ans.push_back(a[0]);
        for(int i = 1 ; i< n; i++){
            if( a[i] > ans.back()) ans.push_back(a[i]);
            else{
                //find index of just bada element 
                int indx = lower_bound(ans.begin() , ans.end() , a[i]) - ans.begin();
                ans[indx] = a[i];
            }
        }
        return ans.size();
    }
};






//dp with n^2 tc and sc and with n^2 tc and n sc;
/*
class Solution
{
    public:
    int solve( int i , int n , int a[] , int last ,vector<vector<int>> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i][last+1] != -1) return dp[i][last+1] ;
        
        int take = 0 , nottake = 0;
        if(last == -1 || a[i]>a[last]){
            // int newL = a[i];
            take =  1 + solve(i+1 , n , a , i , dp);
        }
        nottake = 0+solve(i+1 , n , a, last , dp);
        
        return dp[i][last +1 ] = max(take , nottake);
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
    //   vector<vector<int>> dp(n , vector<int>(n+1 , -1));
        // vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));   //will use only 1 d array now
    //   return solve( 0 , n , a , -1 , dp);
    
    vector<int> currRow(n+1 , 0);
    vector<int> nextRow(n+1 , 0) ;
    // for(int i = n-1 ; i >=0; i--){
    //     for(int j = i-1 ; j>=-1 ; j--){
    //         int take = 0 ;
    //         if(j==-1 || a[i] > a[j]){
    //             take = 1 + dp[i+1][i+1]; 
    //         }
            
    //         int notake = 0 + dp[i+1][j+1];
            
    //         dp[i][j+1] = max(take ,notake);
    //     }
    // }
    
    
    for(int i = n-1 ; i >=0; i--){
        for(int j = i-1 ; j>=-1 ; j--){
            int take = 0 ;
            if(j==-1 || a[i] > a[j]){
                take = 1 + nextRow[i+1]; 
            }
            
            int notake = 0 + nextRow[j+1];
            
            currRow[j+1] = max(take ,notake);
            
            nextRow = currRow;
        }
    }
    return nextRow[0];
    }
};

*/

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends