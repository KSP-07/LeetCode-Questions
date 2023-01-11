class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mp;
        int cows=0,bulls=0;
        for(int i=0,j=0;i<secret.size();i++,j++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            mp[secret[i]]++;
        }
        for(auto i:guess){
            if(mp[i]){
                // cout<<mp[i]<<endl;
                cows++;
                mp[i]--;
            }
        }
        // cout<<cows<<endl;
        cows=cows-bulls;
        string str=to_string(bulls) +"A" + to_string(cows) + "B";
        return str;
    }
};