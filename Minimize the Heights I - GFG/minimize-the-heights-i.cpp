//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    
    int getMinDiff(int arr[], int n, int k) {
        // code here
        
        sort(arr , arr + n);
        
        int mini = 1e9;
        int maxi = -1e9;
        int result = 1e9;
        
        for(int i = 1 ; i < n ; i++ ){
            mini = min (arr[0] +k , arr[i] - k) ;
            maxi = max (arr[i - 1] + k  , arr[n-1] - k) ;
            
            result = min (result , maxi - mini) ;
        }
        result = min(result , arr[n-1] - arr[0]) ;
        
        return result ;
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