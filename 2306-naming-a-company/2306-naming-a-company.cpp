class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        int n=ideas.size();
         long long cnt=0;
        
        unordered_set<string> st(ideas.begin() , ideas.end());
        
        //naive approach mai pairing krne pe n^2 jaarha thaa to hum pairs ke liye ek array lerhe 26 * 26 kii..kuki sirf first letter ka dekhna hai dono words mai
        vector<vector<int> >dp(26, vector<int>(26,0));
        
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
        // cout<<'t'-'a';
        
        //isme i se jo word suru horha agr wo 1 hai ya jada pure column mai..aur jth row pe wo 0 hai to 0 hojayga nhi to pair aajayge 
        //ex=> a , c and c, a agr pair kr skte hia toh fir [c][a] * [a][c] , pair de denge..agr ek nhi 0 hua mtln wo set mai tha toh 0 pair bngea
        
        //coffee aur toffee ke vjh se c aur t pe 0 hoga to 1 pair coffee ki side aur ek toffee ki side se
        //aur jo letter ideas mai thee hii nhii wp column wise 0 hii rhh jayge to kisi bahr ke words se pair nhi hoga
        //aur jinke sath hona hoga , wo 1 by 1 jab unka traversal aayga tab hojayga
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                cnt+= dp[i][j]* dp[j][i];
            }
        }
        return cnt;
    }
};