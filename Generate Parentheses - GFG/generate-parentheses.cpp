//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve( int open , int close , vector<string> &ans , string out){
                //jab dono 0 hojay tab ans miljata hai
        if( open == 0 and close == 0){
            ans.push_back(out);
            return;
        }
        //hum log hmesa hii open laga skte hai , iska koi issue nhi hoga
        if( open != 0){
        //ek new string lii usme add krra charater and ab usse aage bhej rhe...khali out + '(' bhi kr skte thee
            solve ( open -1 , close , ans , out + '(');
        }
        //hum log sirf tab hii close laga skte hai jab kamse kamse kam ek open use hua ho
        if( close > open ){
            solve ( open , close -1 , ans , out + ')');
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        int open = n ;
        int close = n ;
        vector<string> ans;
        string out = "";
        solve(open , close , ans , out ) ;
        return ans; 
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends