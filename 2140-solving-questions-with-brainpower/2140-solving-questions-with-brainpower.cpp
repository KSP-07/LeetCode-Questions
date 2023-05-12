class Solution {
public:
//     long long solve( vector<vector<int>>& ques , int i , int n){
//         if(i>=n) return 0;
        
//         return max(ques[i][0] + solve(ques , i + ques[i][1] +1, n) , solve(ques , i+1 , n));
//     }
    long long mostPoints(vector<vector<int>>& ques) {
        int n = ques.size();
        vector<long long> dp(n,0);
        dp[n-1] = ques[n-1][0];
        
        for(int i = n-2 ; i >=0 ;i--){
            dp[i] = ques[i][0] ;
            int skip = ques[i][1];
            if(i + skip +1 < n){
                dp[i] += dp[ i + skip +1];
            }
            
            dp[i] = max(dp[i] , dp[i+1]);
        }
        
        return dp[0];
        // return solve( ques , 0 , n);
    }
};