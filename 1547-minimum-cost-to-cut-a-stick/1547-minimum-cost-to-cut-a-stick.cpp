class Solution {
public:
    int solve( vector<int> &cuts , vector<vector<int>> &dp , int i , int j){
        // the smallest rod has length of 1
        if(j-i <=1 ) return 0;
        
        // if the cost is calculated before, return immediately
        if(dp[i][j]!=-1) return dp[i][j];
        //we intialise the large number since we are looking for the minimum ans;
        
        int ans = 1e9;
        
        for(int k = i+1 ; k < j ; k++){
            // if this rod is to be cut, the cost is the length, 
            // i.e. cuts[j] - cuts[i]
            // after the cut, it will be split into two parts
            // then we calculate the cost for left rod : dfs(cuts, i, k) 
            // and the cost for the right rod: dfs(cuts, k, j)
            ans = min(ans , cuts[j] - cuts[i] + solve(cuts , dp , i ,k ) + solve(cuts , dp , k , j));
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin() , cuts.end());
        
        vector<vector<int>> dp(105 , vector<int> (105 , -1));
        return solve(cuts , dp , 0 , cuts.size()-1);
    }
};