//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int i, int last , int n , int a[]){
        if(i==n) return 0;
        
        int pick = 0;
        if(last==-1 || abs(a[last] - a[i]) == 1){
            pick = 1 + solve(i+1 , i , n , a);
        }
        int nopick = solve(i+1 , last , n , a);
        return max(pick , nopick);
    }

void printdp(vector<int> &arr){
    for(auto i:arr) cout<<i<<" ";
    cout<<endl;
}
//why sorting would not work> -> take this test case for example...[4 , 5 , 4 , 5 , 4, 5 , 4 , 5] + sorting -> 44445555
    int longestSubsequence(int n, int arr[])
    {
        // code here
        // int cnt = 1;
        // return solve( 0 , -1, N , A);
        
        vector<int>dp(n+1,1);
        int maxans=1;
        for(int i=0;i<n;i++){
            int temp=1;
            for(int j=0;j<i;j++){
                if(abs(arr[i]-arr[j])==1){
                    // cout<<arr[j]<<" "<<j<<" "<<arr[i]<<endl;
                    // cout<<dp
                        temp=max(dp[j+1]+1,temp);
                }
            }
            // printdp(dp);
            dp[i+1]=temp;
            // printdp(dp);
            maxans=max(maxans,dp[i+1]);
        }
        
        return maxans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends