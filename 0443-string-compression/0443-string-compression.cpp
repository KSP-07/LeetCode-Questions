class Solution {
public:
    int compress(vector<char>& chars) {
        string temp = "";
        int n=chars.size();
        if(n==0 || n==1) return n;
        // for(int i=0; chars[i]!='\0';i++) n++;
        for(int i=0;i <n;i++){
            temp+=chars[i];
            if(i<n-1 && chars[i]==chars[i+1]){
                int j = i+1;
                int cnt=1;
                while(j<n && chars[j]==chars[i]){
                    j++;
                    cnt++;
                }
                temp+= to_string(cnt);
                i=j-1;
            }
        }
        chars.clear();
        // vector<char> ans;
        for(int i=0;i<temp.size();i++){
            chars.push_back(temp[i]);
        }
        return temp.size();
    }
};