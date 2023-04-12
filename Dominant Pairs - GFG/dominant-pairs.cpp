//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int Bsearch(vector<int> &arr , int low , int high, int x){
        int index = -1;
        while(low<=high){
            int mid = (low + high)/2;
            if(arr[mid] >= x ){
                index = mid;
                low = mid +1 ;
            }
            else{
                high = mid -1;
            }
        }
        return index;
    }
    int dominantPairs(int n,vector<int> &arr){

        int ans = 0;
        sort(arr.begin()  ,arr.begin()+ (n/2) , greater<int>() );

        for(int i = n/2 ; i < n ; i++){
            int index = Bsearch(arr , 0 ,( n/2) -1 , arr[i]*5);;
            if(index < 0) continue;
            ans+= (index +1);
        }
        return ans;
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
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends