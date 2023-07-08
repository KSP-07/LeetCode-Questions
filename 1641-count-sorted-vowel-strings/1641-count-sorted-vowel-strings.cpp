/*
class Solution {
public:
    
    void solve(int n, vector<string> &temp , string str , vector<char> &vowels){
        if(str.size() == n ){
            // cout<<str<<endl;
            temp.push_back(str);
            return;
        }
        
        for(auto i : vowels){
            int size = str.size();
            if(size > 0 && str[size - 1]<= i){
                // (cout<<str[size - 1]<<" "<<i<<endl);
                solve(n , temp , str+i , vowels);
            }
            else if(size==0){
                solve( n , temp , str+i , vowels);
            }
        }
    }
    int countVowelStrings(int n) {
        vector<string> temp ;
        string str = "";
        vector<char> vowels(5);
        vowels[0] = 'a';
        vowels[1] = 'e';
        vowels[2] = 'i';
        vowels[3] = 'o';
        vowels[4] = 'u';
        solve(n , temp , str , vowels);
        
        return temp.size();   
    }
};
*/

class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5 , 1) ;
        
        if(n == 1 ) return 5;
        
        for(int i = 2; i<= n ; i++ ){
            for(int j = 3 ; j>=0 ; j--){
                dp[j] += dp[j+1] ;
            }
        }
        
        int ans = 0 ;
        for( auto i: dp) ans += i;
        
        return ans;
    }
};