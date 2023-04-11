class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        int i= n-1;
        int cnt = 0;
        string res="";
        while(i>=0){
            if(s[i]=='*'){
                int j = i;
                while(j>=0 && s[j]=='*'){
                    cnt++;
                    j--;
                }
                i=j;
            }
            else if(cnt==0){
                res.push_back(s[i]);
                i--;
            }
            else cnt-- , i--;
        }
        reverse(res.begin() , res.end());
        return res;
    }
};