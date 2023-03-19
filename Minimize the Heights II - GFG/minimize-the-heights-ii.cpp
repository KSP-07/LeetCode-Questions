//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
  //concept according to me is that  , aage wala kam krke aur curr wala bdha ke hii diff min hoga
  //to hum simultaneos check krte rhte ki aage wala kam krke aur abhi wala bdhayge to ans min hota ki nhi , aur ek suru mai le hii lete
  //ki kuch nhi hua toh ye itna toh hai hiii
    int getMinDiff(int arr[], int n, int k) {
        // code here
        //this will place the smallest element on the first positon and the largest element on the last position
        sort(arr  , arr + n);
        
        //this will the store the curr ans, as the initial difference between smallest and largest
        int ans = arr[n-1] - arr[0];
        
        //making inital changes on the first ans last element
        int smallest = arr[0] + k;
        int largest = arr[n-1] -k;
        int mi , ma;
        
        for(int i=0; i<n-1;i++){
            //always comparing with the inital smalles and largest
            mi = min( smallest , arr[i+1] - k);
            ma = max(largest , arr[i] + k);
            if(mi < 0) continue;
            ans = min( ans , ma - mi);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends