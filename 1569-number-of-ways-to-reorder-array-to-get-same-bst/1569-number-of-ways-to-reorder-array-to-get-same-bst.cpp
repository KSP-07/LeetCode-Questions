class Solution {
public:
    int mod = 1e9+7;
    
    long long dfs(vector<int> &nums , vector<vector<long long>> &dp){
        int m = nums.size();
        if(m < 3 ) return 1;
        
        vector<int> leftNodes , rightNodes;
        
        for(int i = 1 ; i<m ; i++){
            if(nums[i] < nums[0]){
                leftNodes.push_back(nums[i]);
            }
            else{
                rightNodes.push_back(nums[i]);
            }
        }
        
        long long leftWays = dfs(leftNodes , dp)%mod;
        long long rightWays = dfs(rightNodes , dp)%mod;
        
        return (((leftWays*rightWays)%mod) * dp[m-1][leftNodes.size()])%mod;
    }
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1);
        for(int i = 0 ; i < n +1 ; i++ ){
            dp[i] = vector<long long> (i+1 , 1 );
            
            for(int j = 1 ; j < i ; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            }
        }
        return (dfs(nums , dp)-1)%mod;
    }
};