//YE HAI AAM JINDGI
// class Solution {
// public:
    
//     int help(int i, vector<int> &c){
//         if(i >=c.size()) return 0;
//         int op1=help(i+1 , c);
//         int op2= help(i+2 , c);
//         return min(op1, op2) + c[i];
//     }
    
//     int minCostClimbingStairs(vector<int>& cost) {
//         return min(help(0,cost) , help(1,cost));
//     }
// };

 //YE HAI MENTOS JINDGI
//top down dp
// class Solution {
// public:
//     int dp[1001];
//     int help(int i, vector<int> &c){
//         if(i >=c.size()) return 0;
//         if(dp[i]!= -1) return dp[i];
//         int op1=help(i+1 , c);
//         int op2= help(i+2 , c);
//         return dp[i]= min(op1, op2) + c[i];
//     }
    
//     int minCostClimbingStairs(vector<int>& cost) {
//         memset(dp, -1,sizeof dp);    //to intialise with -1;
//         return min(help(0,cost) , help(1,cost));
//     }
// };


 //YE HAI MENTOS JINDGI
//bottom dp
// class Solution {
// public:

//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         vector<int> dp(n+2);
//         dp[n]=0;
//         dp[n+1]=0;
//         for(int i=n-1;i>=0;i--){
//             dp[i]=cost[i] + min(dp[i+1] ,  dp[i+2]);
//         }
//         return min(dp[0], dp[1]);
//     }
// };


//YE HAI MENTOS JINDGI
//bottom dp
class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp1=0,dp2=0;
        for(int i=n-1;i>=0;i--){
            int dpi=cost[i] + min(dp1 ,  dp2);
            dp2=dp1;
            dp1=dpi;
        }
        return min(dp1, dp2);
    }
};

