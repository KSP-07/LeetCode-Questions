//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int solve(vector<int> &price , vector<vector<vector<int>>> &dp , int i , int n , int buy , int cnt){
    if(i==n || cnt == 0 ) return 0;
    
    if(dp[i][buy][cnt] != -1) return dp[i][buy][cnt];
    
     if( buy == 0 ){
         return dp[i][buy][cnt] = max(-price[i] + solve(price , dp , i+1 , n , 1 , cnt) , solve(price , dp , i +1 , n , 0  , cnt) );
     }
     else{
         return dp[i][buy][cnt] = max(price[i] + solve(price , dp , i+1 , n , 0  , cnt -1) , solve(price , dp , i +1 , n , 1  , cnt));
     }
}

int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
    vector<vector<vector<int>>> dp(n , vector<vector<int>> (2 , vector<int> (3 , -1)));
    int net = 0;
    return solve(price , dp , 0 , n , 0 , 2);
    // for(auto i: dp) cout<<i<<" ";
    // return -1;
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends