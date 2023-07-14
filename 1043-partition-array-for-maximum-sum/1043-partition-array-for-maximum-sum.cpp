class Solution {
public:
    int f (vector<int> &nums , int i , int k , vector<int> &dp) {
        int n = nums.size();
        if( i == n ) return 0 ;
        if( dp[i] != -1 ) return dp[i] ;
        
        int len = 0 ;
        int maxi = INT_MIN ;
        int maxAns = INT_MIN ;
        
        for (int ind = i ; ind < min ( i + k , n ) ; ind++ ) {
            len++ ;
            maxi = max ( maxi , nums[ind]) ;
            int sum =( maxi * len) + f ( nums , ind +1 , k , dp ) ;
            
            maxAns = max (maxAns , sum ) ;
        }
        
        return dp[i] = maxAns ; 
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<int> dp ( n , -1 ) ;
        
        return f(arr , 0 , k , dp ) ;
    }
};