/*
recursive soluton

class Solution {
public:
    bool scramble(string s , string t){
        int n = s.size();
        if(s==t) return true;
        
        vector<int> cnt(26,0);
        for(int i=0; i<n;i++){
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']--;
        }
        for(auto i: cnt) if(i>0) return false;
        
        //2 cases->for scrambled and not scrambled
        for(int i=1 ; i<n;i++){
            if(scramble(s.substr(0 , i) , t.substr(0,i)) && scramble(s.substr(i) , t.substr(i)) ) return true;
            if(scramble(s.substr(0 , i) , t.substr(n-i)) && scramble(s.substr(n-1) , t.substr(0,i))) return true;
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        return scramble(s1 , s2);
    }
};

*/

class Solution {
   map<pair<string,string>, bool> dp;
public:
   
    
    bool scramble(string s, string t){
        int n= s.size();
        pair<string , string> combo= make_pair(s,t);

        if( dp.count(combo)  != 0)
            return dp[combo];
        if(s==t)
            return true;
        vector<int> cnt(26,0);
        for(int i=0; i<n; i++)
            cnt[s[i]-'a']++, cnt[t[i]-'a']--;

        for(int i=0; i<26; i++)
            if( cnt[i] )
                return false;

        // s=gr|eat  t=gr|eat   (not scrambled)
        // s=gr|eat  t=ate|gr   (scrambled)
        
        for(int len=1; len<n; len++){
           
            if( scramble(s.substr(0,len), t.substr(0,len)) and scramble(s.substr(len), t.substr(len))  
|| scramble(s.substr(0,len), t.substr(n-len)) and scramble(s.substr(len), t.substr(0,n-len))){
                
                return dp[combo]=true;
            }
                
        }        
        return dp[combo]=false;
    }
    bool isScramble(string s, string t) {

        return scramble(s,t);
    }
};