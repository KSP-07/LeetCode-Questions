class Solution {
public:
    bool wordComp(unordered_map<char, int> &mp , string s1, string s2){
        int i=0,j=0;
        while(i<s1.size() && j<s2.size()){
            int pos1=mp[s1[i]];
            int pos2= mp[s2[j]];
            
            if(pos1<pos2) return true;
            else if(pos1>pos2) return false;
            
            //if same keep comparing
            i++;
            j++;
        }
        
        //control will come here if the chars compared are equal
        //so smaller length word will be smaller in lex order
        
        return (s1.size()<= s2.size());
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        
        for(int i=0;i<order.size();i++) mp[order[i]]=i;  //storing char rank wise in map
        
        for(int i=0;i<words.size() -1 ;i++){
            if(!wordComp(mp , words[i] , words[i+1])) return false;
        }
        return true;
    }
};





/*

converting words to into their respective ranks
        unordered_map<char,char> map;
        
        for(int i=0;i<26;i++){
            map[order[i]]= ('a'+i);
        }
        
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                words[i][j]= map[words[i][j]];
            }
        }
        
        return is_sorted(words.begin(),words.end());
    }
    */