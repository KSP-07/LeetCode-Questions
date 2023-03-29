class Solution {
public:
    int solve(vector<int> &arr , int i , int index, int n , vector<vector<int>> &dp ){
        if(i>=n ) return 0;
        if(dp[i][index] !=-1) return dp[i][index] ;
        int sum =0;
        
        //pick
        int tsum1 = (index *arr[i]) +solve(arr , i+1 , index+1 , n , dp);
        
        //not pick
        int tsum2 = solve(arr , i+1 , index ,n , dp);
        sum= max(tsum1 ,tsum2);
        return dp[i][index]  = sum;
    }
    int maxSatisfaction(vector<int>& arr) {
        int n  = arr.size();
        sort(arr.begin() , arr.end());
        
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return solve(arr , 0 , 1 , n , dp);
    }
};