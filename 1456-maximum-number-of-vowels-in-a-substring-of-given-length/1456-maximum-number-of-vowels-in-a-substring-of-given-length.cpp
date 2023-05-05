class Solution {
public:
    int maxVowels(string s, int k) {
        int max_cnt = INT_MIN;
        int n = s.size();
        int i = 0, j =0 , cnt =0;
        while(j<n){
            if(s[j] == 'a' || s[j]=='e' || s[j] == 'i' || s[j]=='o' || s[j] == 'u') cnt++;
            // cout<<s[j]<<" "<<cnt<<endl;
            if(j-i + 1 == k){
                max_cnt = max(max_cnt , cnt);
                if(s[i] == 'a' || s[i]=='e' || s[i] == 'i' || s[i]=='o' || s[i] == 'u') cnt--;
                // cnt = 0;
                i++;
            }
            j++;
        }
        max_cnt = max(max_cnt , cnt);
        return max_cnt;
    }
};