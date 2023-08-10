class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        
        if(n==1) return 1;
        if(n == 2) {
            if(s[0] == s[1]) return 3;
            else return 2;
        }
        
        int cnt = 0 ;
        //counting odd length palindrome
        
        for(int i = 0 ; i < n ; i++){
            int l = i ;
            int r = i ;
            
            while(l >= 0 && r < n && s[l] == s[r] ) {
                cnt++;
                l--;
                r++;
            }
            
            //counting even length palindrome
            l = i;
            r = i+1;
            while( l>= 0 && r < n && s[l]==s[r]){
                cnt++;
                l--;
                r++;
            }
        }
        return cnt ;
    }
};