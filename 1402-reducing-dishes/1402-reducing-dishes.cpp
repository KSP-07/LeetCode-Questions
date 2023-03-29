class Solution {
public:
    /* 
    Memoization
    
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
    */
    
    //tabulation
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        // Mark all the states initially as 0.
        vector<vector<int>> dp(satisfaction.size() + 1, vector<int>(satisfaction.size() + 2, 0));
        for (int index = satisfaction.size() - 1; index >= 0; index--) {
            for (int time = 1; time <= satisfaction.size(); time++) {
                // Maximum of two choices:
                // 1. Cook the dish at `index` with the time taken as `time` and move on to the next dish with time as time + 1.
                // 2. Skip the current dish and move on to the next dish at the same time.
                dp[index][time] = max(satisfaction[index] * time + dp[index + 1][time + 1], dp[index + 1][time]);
            }
        }
        return dp[0][1];
    }
};