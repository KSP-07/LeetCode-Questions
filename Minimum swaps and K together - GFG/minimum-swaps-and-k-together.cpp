//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
//sliding window
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int fav =0;
        for(int i=0; i<n;i++){
            if(arr[i]<=k) fav++;
        }
        
        int non_fav = 0;
        int ans = INT_MAX;
        int i=0 ,j=0;
        while(j<n){
            if(arr[j]>k) non_fav++;
            if(j-i +1 ==fav){
                ans= min(ans , non_fav);
                
                if(arr[i++]>k) non_fav--;
            }
            j++;
        }
        
        return ans==INT_MAX? 0:ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends