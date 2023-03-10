//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n = s.size();
		    vector<string> ans;
		    //i<<n -1 is 2^n ,as these many possibility of solutions are there
		    for(int i=0;i<(1<<n);i++)
		    {
		        string sub ="";
		        for(int j=0;j<n;j++)
		        {
		            //checks if curr bit is set or not
		            if(i&(1<<j))
		               sub+=s[j];
		        }
		        if(sub.size()>0)
		           ans.push_back(sub);
		    }
		    sort(ans.begin() , ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends