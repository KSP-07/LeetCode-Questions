class Solution {
public:
    int mod = 1e9 +7;

    long long solve(int target , int zero , int one  , vector<long long> &dp){
        if(target == 0) return 1;
        if(target <0) return 0;
        if(dp[target] != -1) return dp[target];
        return dp[target] = solve(target - one , zero , one, dp)%mod + solve(target - zero , zero , one, dp)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        vector<long long> dp(high+1 , -1);
        for(int i = low ; i<=high ; i++){
            ans = ((ans)%mod+ solve(i , zero , one, dp))%mod;
        }
        return ans;
    }
};