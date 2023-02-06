//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
		void func(string s , string out, vector<string>&ans){
		    // to insert only unique output
		    if(s.size()==0){
		        if(find(ans.begin(), ans.end() ,out)==ans.end()){
		            ans.push_back(out);
		            return;
		        }
		    }
		    
		    for(int i=0;i<s.size();i++){
		        char ch=s[i];
		        string left = s.substr(0 ,i);
		      //  cout<<ch<<" "<<left<<" ";
		        string right = s.substr(i+1);
		     //   cout<<right<<" ";
		        string newS= left+right;
		      //  cout<<newS<<endl;
		        func(newS , out + ch ,ans);
		      //  cout<<endl;
		    }
		    
/*
this is how it works:
For Input: 
ABC
Your Output: 
A  BC BC
B  C C
C  


C B  B
B  



B A C AC
A  C C
C  


C A  A
A  



C AB  AB
A  B B
B  


B A  A
A  



ABC ACB BAC BCA CAB CBA

*/
		    
		    
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