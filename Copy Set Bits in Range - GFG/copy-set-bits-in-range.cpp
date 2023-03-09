//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        // l and r must be between 1 to 32
       // (assuming ints are stored using
       //  32 bits)
       if (l < 1 || r > 32) return -1;
       
       for(int i=l; i<=r;i++){
           // Find a mask (A number whose
           // only set bit is at i'th position)
           int mask = 1 << (i-1);
           
          // If i'th bit is set in y, set i'th
           // bit in x also.
           if(y & mask) x= x| mask;
       }
       return x;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends