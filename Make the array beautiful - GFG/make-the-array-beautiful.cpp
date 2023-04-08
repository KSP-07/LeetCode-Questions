//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int> stk;
        for(auto i: arr){
            if(stk.size()==0){
                stk.push(i);
            }
            else{
                if((stk.top()>=0 and i<0) || (stk.top()<0 and i>=0)) stk.pop();
                else stk.push(i);
            } 
        }
        vector<int> ans;
        while(stk.size()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends