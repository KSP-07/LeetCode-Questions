class Solution {
public:
    
    void solve(int open , int close , vector<string> &ans  , string out){
        
        //jab dono 0 hojay tab ans miljata hai
        if(open == 0 && close == 0 ){
            ans.push_back(out);
            return;
        }
        //hum log hmesa hii open laga skte hai , iska koi issue nhi hoga
        if( open>0){
            //ek new string lii usme add krra charater and ab usse aage bhej rhe...khali out + '(' bhi kr skte thee
            string new_out = out + '(';
            solve(open - 1, close , ans , new_out );
        }
        
        //hum log sirf tab hii close laga skte hai jab kamse kamse kam ek open use hua ho
        if(close > open ){
            string new_out = out + ')';
            solve(open , close -1 ,ans , new_out );
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        int open = n ;
        int close = n ;
        vector<string> ans;
        string out = "";
        solve(open , close , ans , out ) ;
        return ans;
    }
};