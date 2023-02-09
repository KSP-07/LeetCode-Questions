class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        int n=ideas.size();
         long long cnt=0;
        
        unordered_set<string> st(ideas.begin() , ideas.end());
        
        vector<vector<int> >dp(26, vector<int>(26));
        
        for(int i=0;i<n;i++){
            string temp = ideas[i];
            int s= temp[0] -'a';
            
            for(int j=0; j< 26 ;j++){
                temp[0] = j+'a';
                
                if(st.find(temp)==st.end()){
                    
                    dp[s][j]++;                    
                }
            }
            
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                cnt+= dp[i][j]* dp[j][i];
            }
        }
        return cnt;
    }
};