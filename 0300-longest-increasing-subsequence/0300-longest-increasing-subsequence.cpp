class Solution {
public:
    int solve ( vector<int> &nums , int i , int prev ,vector<vector<int>>& dp) {
        
        if(i == nums.size()) return 0 ;
        
        if(dp[i][prev+1] != -1) return dp[i][prev+1] ;
        if(prev==-1 || nums[prev] < nums[i]){
            return dp[i][prev+1]  =  max(1 + solve(nums , i+1 , i , dp) , solve(nums , i+1 , prev , dp)) ;
        }
        else return dp[i][prev+1] = solve(nums , i+1 , prev ,dp) ;
                       
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1 ;
        int ans = 1 ;
        int cnt = 0 ;
        
        vector<vector<int>> dp(nums.size() , vector<int> (nums.size()+1 , -1));
        
        return solve ( nums , 0 , -1, dp) ;
    }
};