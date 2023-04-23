class Solution {
public:
    
    int MOD = 1000000007;
    
    int solve(string &s , int &k , int indx , vector<int> &dp){
        if(indx == s.size()) return 1;
        
        if(dp[indx] != -1 ) return dp[indx];
        
        long long ways = 0 , currNum = 0;
        
        for(int i = indx; i < s.size() ; i++){
            int currDig = s[i] - '0';
            
            currNum = (currNum * 10) + currDig;
            
            if(currNum <1 || currNum > k) break;
            
            int next = solve( s , k , i+1 , dp);
            ways = (ways + next) %MOD ;
        }
        
        return dp[indx] = ways;
    }
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size() , -1);
        
        return solve(s , k , 0 ,dp);
    }
};