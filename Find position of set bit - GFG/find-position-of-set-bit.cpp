//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        
        if(N<1) return -1;
        //if N is not in power of 2
        if(N & (N-1)) return -1;
        
        //uses space of log2
        // return log2(N) +1;
        
        
        //usign right shift
        int cnt=0;
        while(N){
            cnt++;
            N = N>>1;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends