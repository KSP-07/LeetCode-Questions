//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        int cnt  = 0;
        stack<pair<int,int>> st;
        // st.push({color[0] , radius[0]});
        int i=0;
        while(i<N){
            if(!st.empty() ){
                auto it = st.top();
                if(it.first == color[i] && it.second == radius[i]){
                    st.pop();
                    i++;
                    continue;
                }
            }
            st.push({color[i] , radius[i]});
            // cout<<st.top().first<< " "<<st.top().second<<endl;
            i++;
        }
        // if(i==N-1) cnt++;
        return st.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends