class Solution {
public:
    int solve(vector<vector<int>> &v,vector<vector<int>> &dp,int s,int k,int &n){
        if(s>=n)return 0;
        if(k==0)return 0;
        if(dp[s][k] != -1)return dp[s][k];
        int mx = solve(v,dp,s+1,k,n);   //not picking from current
        int cur = 0;
        for(int i = 0; i < v[s].size(); i++){
            cur += v[s][i];   //picking from current and then checking if it will give max
            if(i < k){
                //will check if including curr elements will give max or excluding these
                mx = max(mx,cur+solve(v,dp,s+1,k-(i+1),n));
            }
        }
        return dp[s][k] = mx;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        return solve(piles,dp,0,k,n);
    }
};