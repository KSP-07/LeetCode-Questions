class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;  //freq lene ke liye ek map use kr rhee hai
        
        for(int i=0;i<cpdomains.size();i++){
            string str="";  //ye string wala part trim krke lene ke liye
            string nums ="";  //ye first num jo hai wo store krane ke liye
            
            //phla space aane tkk num hai 
            for(int j=0; cpdomains[i][j]!=' ';j++){
                nums+= cpdomains[i][j];
            }
            int n = stoi(nums);   //number ko int mai le lia
            
            //ab since com alag se aaskta hai priority jada hai use toh piche se surr kr rhe aur ek hint ye bhi hai ki ' ' pe aake traverse khtm ho jayga
            for(int j=cpdomains[i].size()-1;cpdomains[i][j]!=' ';j--){
                if(cpdomains[i][j]=='.') mp[str]+=n;
                str+=cpdomains[i][j];   //agar value phle lete to .com map mai jaata....baad mai lene se leetcode. jayga , aur leetcode ke baad hmesa hii ek . rhega
            }
            mp[str]+=n;   //ye puri string jitni obtain hue usko stroe krr liaa
        }
        
        
        vector<string> ans;
        for(auto i:mp){
            
            //map se string lerha , usko reverse kr rhee sidha krne ke liye
            string t = i.first;
            reverse(t.begin() , t.end());
            //ab num lia aur usme add krdi strings
            string str= to_string(i.second) + ' ' + t;
            ans.push_back(str);            
        }
        return ans;
    }
};