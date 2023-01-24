// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int Maximize(int arr[],int n)
    {
        // Complete the function
        // int size = sizeof(arr) / sizeof(arr[0]);
        sort(arr,arr+n);
        long long int mod = pow(10,9)+7;
        long long int sum=0;
        for(long int i=0;i<n;i++){
            sum+=(arr[i]*i);
        }
        return sum%mod;
    }
};

// { Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}  // } Driver Code Ends