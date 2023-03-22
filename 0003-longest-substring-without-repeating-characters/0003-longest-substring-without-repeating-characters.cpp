class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size();
        if(len<1) return 0;
        vector<int> count(260,0);   //ascii length of 255
        int i=0,j=0;
        count[s[0]]++;              //could crash if string is empty
        int ans=1;
        while(j!=len-1){
            if(count[s[j+1]]==0){
                j++;
                count[s[j]]=1;
                ans=max(ans,j-i+1);
            }
            else{
                count[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};