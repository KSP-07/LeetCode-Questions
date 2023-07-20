//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[501][2001];
    int recur(int i,vector <int> &nums,int space,int &k){
        if(i == nums.size()) return 0;
        if(dp[i][space] != -1) return dp[i][space];
        int cost = pow(space+1,2);    //agar word ko use krte toh fir, rem se ek extra minus krte, but use nhi kr rhee to wo chora hua blank bhi count krenge
        if(nums[i] <= space) return dp[i][space] = min(recur(i+1,nums,space-nums[i]-1,k),cost+recur(i+1,nums,k-nums[i]-1,k));   //nhi lene pe k se minus isliye kr rhee kuki, ab iss line mai nhi lia mtlb wo next line mai lenge,to cuu line ki cost add krke next line mai put kr rhee
        return dp[i][space] = cost+recur(i+1,nums,k-nums[i]-1,k);
    }
    int solveWordWrap(vector<int>nums, int k) {
        memset(dp,-1,sizeof(dp));
        return recur(0,nums,k,k);
    } 
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends