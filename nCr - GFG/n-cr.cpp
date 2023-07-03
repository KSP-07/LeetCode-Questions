//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int mod = 1e9+7;
    int nCr(int n, int r){
        // code here
        /*
        int res = 1 ;
        for( int i = 0 ; i < r ; i++ ){
            res = res * (n-i);
            res /= (i+1);
            res = res %mod;
        }
        return res%mod;
        */
        
        int C[r+1] = {0};
        C[0] = 1 ;
        C[1] = 1 ;
        
        for( int i = 2 ; i <= n ; i++ ){
            for( int j = r ; j > 0 ; j-- ){
                C[j] = ( C[j] + C[j-1] ) % mod ;
            }
        }
        return C[r] ;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends