class Solution {
public:
    
    int f ( vector < int > & nums , int i , int j , vector < vector < int > > & dp ) {
        
        if ( i > j ) return 0 ;
        
        if ( dp [i] [j] != -1 ) return dp [i][j] ;
        
        int ans = INT_MIN ;
        
        for (int k = i ; k <= j ; k++ ) {
            int cost = ( nums[ i - 1 ] * nums [ k ] * nums [ j + 1 ] ) + f ( nums , i , k - 1 , dp ) + f (nums , k+1 , j , dp ) ;
            
            ans = max ( ans , cost ) ;
        }
        
        return dp[i][j] = ans ;
        
    }
    
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size() ;
        nums.push_back(1);
        nums.insert(nums.begin() ,1);
        
        
        vector < vector < int > > dp (n + 1 , vector <int> ( n + 1 , -1 )) ;
        
        return f( nums , 1 , n , dp ) ;
    }
};