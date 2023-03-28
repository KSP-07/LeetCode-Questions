/*
bottom up dp solution

int solve(int index , int buy , vector<int>& prices , int limit , vector<vector<vector<int>>> &dp){
    if(index>=prices.size()) return 0;
    if(limit<=0) return 0;
    if(dp[index][buy][limit]!= -1) return dp[index][buy][limit];
    int profit = 0;
    if(buy){
        int buykaro = -prices[index] +  solve(index+1 ,0 , prices , limit, dp);
        int skipkaro = 0 +  solve(index+1 , 1 , prices , limit, dp );
        profit = max(buykaro  , skipkaro);
    }
    else{
        int sellkaro = prices[index] + solve(index +1 , 1 , prices , limit-1, dp);
        int skipkaro = 0 + solve(index+1 , 0 , prices , limit, dp);
        profit = max(sellkaro , skipkaro);
    }
    return dp[index][buy][limit] = profit;
}
*/

int solveTab(vector<int> &prices){
    int n = prices.size();

    // vector<vector<vector<int>>> dp(n+1 , vector<vector<int>> (2 , vector<int>(3 , 0)));
    
    vector<vector<int>> curr(2 , vector<int> (3 ,0));
    vector<vector<int>> next(2 , vector<int>(3 ,0));
    
    for(int index = n-1; index>=0 ; index--){
        for(int buy = 0 ; buy <= 1 ; buy++){
            for(int limit =1; limit<=2 ; limit++){
                int profit = 0;
                if(buy){
                    int buykaro = -prices[index] +  next[0][limit];
                    int skipkaro = 0 +  next[1][limit];
                    profit = max(buykaro  , skipkaro);
                }
                else{
                    int sellkaro = prices[index] + next[1][limit -1];
                    int skipkaro = 0 + next[0][limit];
                    profit = max(sellkaro , skipkaro);
                }
                curr[buy][limit] = profit;
            }
            next = curr;
        }
    }
    // return dp[0][1][2];
    
    return next[1][2];
}

int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
    // vector<vector<vector<int>>> dp(n , vector<vector<int>> (2 , vector<int>(3 , -1)));
    // return solve(0,1, price , 2 , dp);
    return solveTab(price);
}
