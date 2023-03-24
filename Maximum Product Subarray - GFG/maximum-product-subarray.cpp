//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	
	//taking product from left and right and right to left and returning max among them
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long left_prod =1 , right_prod =1;
	    long long ans = arr[0];
	    for(int i = 0; i<n ;i++){
	        left_prod*= arr[i];
	        right_prod*= arr[n-1-i];
	        
	        ans= max(ans , max(left_prod , right_prod));
	        if(left_prod==0) left_prod= 1 ;
	        if(right_prod==0) right_prod = 1;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends