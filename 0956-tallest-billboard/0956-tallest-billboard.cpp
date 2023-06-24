class Solution {
public:
    //https://www.youtube.com/watch?v=805umyRq7cE
    int helper(vector<int> &rods , vector<vector<int>> &dp , int i ,int diff){
        if(i==rods.size()){
            if(diff==0) return 0;
            return INT_MIN;
        }
        
        if(dp[i][diff + 5000] != -1) return dp[i][diff + 5000];
        
        int opt1 = helper(rods , dp , i+1 , diff);
        int opt2 = rods[i] + helper(rods , dp , i+1 , diff+ rods[i]);
        int opt3 = helper(rods , dp , i+1 , diff - rods[i]);
        
        return dp[i][diff + 5000] = max(opt1 , max(opt2 , opt3));
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<int>> dp(n+1 , vector<int> (20001 , -1));
        return helper(rods , dp , 0 , 0);
    }
};