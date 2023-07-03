class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int n = s.size() ;
        int m = goal.size() ;
        
        if( n != m ) return false ;
        
        if( s == goal){
            unordered_set<char> st(s.begin() , s.end());
            
            return st.size() < m ;
        }
        
        int i = 0 ;
        int j = n-1;
        
        while( i < n && s[i]== goal[i]) i++;
        
        while( j >= 0 && s[j] == goal[j]) j--;
        
        if( i < j ) swap(s[i] , s[j]);
        
        return s == goal;
        
    }
};