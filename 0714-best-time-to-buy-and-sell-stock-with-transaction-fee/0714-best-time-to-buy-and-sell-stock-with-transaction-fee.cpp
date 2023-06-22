class Solution {
public:
    
    int solve(vector<int> &prices , vector<vector<int>> &dp ,int i, int &fee , int flag){
        if(i==prices.size()) return 0;
        
        if(dp[i][flag] != -1) return dp[i][flag];
        
        if(flag){
            return dp[i][flag] = max(-prices[i] + solve(prices , dp , i+1 ,fee , !flag ) , solve(prices , dp , i+1 , fee , flag));
        }
        else{
            return dp[i][flag] = max(prices[i] - fee + solve(prices ,dp, i+1, fee , !flag) , solve(prices ,dp, i+1 , fee ,flag) );
        }
        return -1;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int> (2 , -1));
        
        return solve(prices , dp ,0, fee , 1);
    }
    
};