class Solution {
public:
    int partitionString(string s) {
        vector<int> last_seen(26,-1);
        int ans =1 , substringStart=0;
        int index=0;
        for(int i = 0; i < s.length(); i++){
            if(last_seen[s[i]-'a'] >= substringStart){
                ans++;
                substringStart=i;
            }
            last_seen[s[i]-'a'] = i;
        }
        return ans;
    }
};