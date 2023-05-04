//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        // int i  = 0 , j = 0 ;
        int cnt = 0 ;
        // for(int i =0 ; i< n ; i++){
        //     long long product = 1 ; 
        //     for(int j=i ; j< n; j++){
        //         product *= a[j];
        //         if(product < k ) cnt++;
        //         if(product >= k) break ;
        //      }
        // }
        
        if(n==1){
            if(a[0] < k) return 1;
        }
        long long product = 1;
        for(int i=0, j = 0 ; j<n ; j++){
            product *= a[j];
            if(product < k) cnt += ( j - i +1);
            else{
                while(product >= k && i<=j){
                    product /= a[i];
                    i++;
                }
                if(product<k) cnt += ( j - i +1);
                
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends