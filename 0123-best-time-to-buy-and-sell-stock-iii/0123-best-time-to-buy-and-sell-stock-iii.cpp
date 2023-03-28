class Solution {
public:
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
int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
    vector<vector<vector<int>>> dp(n , vector<vector<int>> (2 , vector<int>(3 , -1)));
    return solve(0,1, price , 2 , dp);
}
};