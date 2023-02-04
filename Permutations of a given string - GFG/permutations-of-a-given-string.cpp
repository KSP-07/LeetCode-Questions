//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
		void func(string s , string out, vector<string>&ans){
		    if(s.size()==0){
		        if(find(ans.begin(), ans.end() ,out)==ans.end()){
		            ans.push_back(out);
		            return;
		        }
		    }
		    for(int i=0;i<s.size();i++){
		        char ch=s[i];
		        string left = s.substr(0 ,i);
		        string right = s.substr(i+1);
		        string newS= left+right;
		        func(newS , out + ch ,ans);
		    }
		}
		vector<string>find_permutation(string S)
		{
		    //using next_permutation
		  //  vector<string> v;
		  //  sort(S.begin(), S.end());
		  //  do{
		  //      v.push_back(S);
		  //  }while(next_permutation(S.begin(), S.end()));
		    
		  //  return v;
		    
		    //using recursion
		    vector<string>ans;
		    string out="";
		    func(S ,out,ans);
		    sort(ans.begin() ,ans.end());
		    return ans;
		}

};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends