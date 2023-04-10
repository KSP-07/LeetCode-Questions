//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        // map<int ,int> mp;
        // for(vector<int> line : lines){
        //     int start = line[0]  , end = line[1] + 1;
        //     mp[start]++;
        //     mp[end]--;
        // }
        // int res =0 , cnt = 0;
        // for(auto i: mp){
        //     cnt += i.second;
        //     res = max(res , cnt);
        // }
        // return res;
        
        vector<int> v1 , v2;
        
        for(auto i: lines){
            v1.push_back(i[0]);
            v2.push_back(i[1]);
        }
        
        sort(v1.begin() , v1.end());
        sort(v2.begin() , v2.end());
        
        int i = 0 , j = 0;
        int cnt = 0  , res =0;
        while(i<N){
            if(v1[i] <= v2[j]){
                cnt++;
                i++;
                res = max(res , cnt);
            }
            else{
                j++;
                cnt--;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends