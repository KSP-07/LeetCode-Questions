class Solution {
public:
    
    int find(vector<vector<int>> &offers , int x){
        
        int l = 0 , r = offers.size() -1 ;
        int ans = -1 ;
        
        while( l<=r){
            int mid = l + (r-l)/2;
            if(offers[mid][0] > x){
                ans = mid ;
                r = mid -1 ;
            }
            else{
                l = mid + 1;
            }
        }
        return ans; 
    }
    
    int solve( vector<vector<int>> &offers , vector<int> &dp , int indx){
        if(indx >= offers.size()) return 0;
        
        if(dp[indx] != -1) return dp[indx] ;
        
        int next_indx  = find (offers , offers[indx][1]);
        
        int accept = offers[indx][2] + solve(offers , dp , next_indx) ;
        
        int d_accept = solve(offers, dp , indx +1 ) ;
        
        return dp[indx] = max(accept , d_accept) ;
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin() , offers.end());
        
        vector<int> dp(offers.size() , -1);
        
        return solve(offers , dp , 0);
        
    }
};