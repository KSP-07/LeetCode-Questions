//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
/*
    //backtracking 
    int solve(int ind ,int arr[] , int n , int sum, int tsum){
        if(sum==tsum){
            return 1;
        }
        for(int i=ind;i<n;i++){
            //ek element pick krke dekh rhee ki iss se banega ki ni
            tsum+=arr[i];
            //ab agla element uthayge
            if(solve(i+1,arr, n , sum , tsum)) return true;
            //ab idr aay mtlb ans nhi bana picked element se toh usse hata rhee , dusra rkh lenge ab uski jagah
            tsum-=arr[i];
        }
        return 0;
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum&1) return 0;   //odd mai equal divide nhi hoskta
        
        //sum ka aadha krkek dekh rhee ki milega ki nhi array mai
        sum/=2;
        return solve(0,arr , N , sum  ,0 , dp);
    }
    
    */
    
    int solve(int arr[] , int n , int sum , vector<vector<int>> &dp){
        if(sum==0) return 1;
        if(n==0 && sum!=0) return 0;
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        if(arr[n-1]<=sum){
            return dp[n][sum] = solve(arr , n-1 , sum - arr[n-1] , dp) || solve(arr , n-1 , sum ,dp);
        }
        else{
            return dp[n][sum]=solve(arr , n-1 , sum ,dp);
        }
    }
    int equalPartition(int N, int arr[]){
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum&1) return 0;   //odd mai equal divide nhi hoskta
        
        //sum ka aadha krkek dekh rhee ki milega ki nhi array mai
        sum/=2;
        
        //dp n and sum+1 isliye lii , kuki knapsack ki trh  , n size mai sum ke barabar ki values leni hai
        vector<vector<int>> dp(N+1 , vector<int> (sum+1,-1));
        return solve(arr , N , sum , dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends