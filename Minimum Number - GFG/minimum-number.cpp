//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
     int minimumNumber(int n,vector<int> &a){
        //sort(a.begin(),a.end());  
        if(n==1){
            return a[0];
        }
        else if(n==2){
            int mn=min(a[0],a[1]);
            int mx=max(a[0],a[1]);
             int k=mx%mn;
             if(k==0){
                 return mn;
             }
        }
        else {
            return 1;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.minimumNumber(n,arr)<<endl;
    }
}
// } Driver Code Ends