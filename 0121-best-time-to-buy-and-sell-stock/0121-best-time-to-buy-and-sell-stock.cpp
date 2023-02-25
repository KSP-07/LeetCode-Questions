class Solution {
public:
//     void solve(){
//         if(bought==0){
            
//         }
//     }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int stock = prices[n-1];
        int maxi = 0 , temp=0;
        for(int i=n-2; i>=0;i--){
            temp = prices[i];
            maxi = max(maxi , stock - temp);
            stock = max(stock , temp);
        }
        return maxi;
    }
};