class Solution {
public:
    int solve(int amt , vector<int> &coins , int n , vector<vector<int>> &dp){
        if(amt == 0) return 1;
        if(n == 0 || amt < 0 ) return 0;
        
        if(dp[n][amt] != -1) return dp[n][amt];
        int pick = 0 , notpick = 0;
        if(coins[n-1] <= amt){
            pick = solve(amt - coins[n-1] , coins , n , dp);
        }
        notpick = solve(amt , coins , n-1 ,dp);
        
        return dp[n][amt] = (pick + notpick);
    }
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        vector<vector<int>> dp(n+1 , vector<int> (amount+1 , -1));
        return solve(amount , coins ,  n ,dp);
    }
};