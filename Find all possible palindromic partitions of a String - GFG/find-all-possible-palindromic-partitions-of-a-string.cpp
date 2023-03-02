//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool check(string s, int l, int h){
        while(l<h){
            if(s[l]!=s[h])
                return false;
            l++; h--;
        }
        return true;
    }
  void solve(string s , int ind , vector<string> res , vector<vector<string>> &ans){
      if(ind==s.size()){
          ans.push_back(res);
        //   cout<<endl;
          return;
      }
      for(int i=ind;i<s.size() ; i++){
          if(check(s,ind,i)){
              //isme phle sbb ek ek char jayga , fir return hone pe , first index ke baad se chalu hoga kuki i aage move krega
              res.push_back(s.substr(ind , i-ind +1));
            //   cout<<s.substr(ind , i-ind +1)<<endl;
              solve(s, i +1 , res , ans);
              res.pop_back();
          }
      }
  }
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        vector<vector<string>> ans;
        vector<string> res;
        solve(s ,0 ,res , ans);
        // cout<<endl;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends