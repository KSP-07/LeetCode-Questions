//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define mod 1000000007
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here  
        
        if(n==1) return a[0];
        
        //neg zero aur pos ka count lerhe...sath mai +ve to include hoga hii toh uska product
        int pos =0 , neg=0 , zero=0 ,maxNeg=INT_MIN;
        long long product=1;
        for(auto x:a){
            if(x>0) {
                pos++;
            }
            else if(x<0){
                //agr neg ka cnt odd aaya to sbse kam value , neg mai max wala hatan hoga
                maxNeg= max(maxNeg ,x);
                neg++;
            }
            else {zero++ ; continue;}
            product=(product*x)%mod;
        }
        if(zero==n) return 0;
        if(zero==n-1 && neg==1) return 0;
        if(neg&1) product/=maxNeg;
        return product%mod;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends