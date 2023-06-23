class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int longest = 2;
        
        int n = nums.size();
        if(n <=2) return longest;
        vector<unordered_map<int,int>> dp(n);
        
        for(int i=0 ; i< n ;i++){
            for(int j = 0 ; j < i ; j++){
                int diff = nums[i] - nums[j];
                dp[i][diff] = dp[j].count(diff) ? dp[j][diff]+1 : 2;
                longest = max(longest, dp[i][diff]);
            }
        }
        return longest;
    }
};