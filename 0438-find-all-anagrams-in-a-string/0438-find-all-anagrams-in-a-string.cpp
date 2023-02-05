class Solution {
public:
    
    //permutation of string find krne jaisa hai....sliding hash use kr rhee....like for small size string ki jitna fix krke dekh rhe kii freq same horhi ki nhi
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash(26,0);
        vector<int> hash2(26,0);
        vector<int> ans;
        
        for(auto i:p) hash[i-'a']++;
        
        int i=0 , j=0;
        while(i<s.size()){
            hash2[s[i]-'a']++;
            
            if(i>=p.size()) hash2[s[j++]-'a']--;
            
            if(hash == hash2) ans.push_back(i+1-p.size());
            i++;
        }
        return ans;
    }
};