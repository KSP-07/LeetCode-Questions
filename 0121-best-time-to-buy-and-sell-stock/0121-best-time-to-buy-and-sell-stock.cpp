class Solution {
public:
/*
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
    */
        int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int minVal=prices[0] , maxProfit=0;
        for(int i=1;i<n;i++){
            if(minVal>prices[i]) minVal=prices[i];
            
            
            //since max=0 , ans will not go -ve , and we are checking for prices[i]-min coz we are looking for max profit in the array we could get with curr min
            
            else if(maxProfit< prices[i]-minVal) maxProfit= prices[i]-minVal;
        }
        return maxProfit;
    }
};