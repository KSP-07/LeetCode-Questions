//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here   
        sort(arr  , arr + N , greater<int> ()) ;
        
        int i = 0 , j = 1;
        int ans = 0 ;
        while(j < N) {
            if( abs(arr[j] - arr[i] ) < K ) {
                ans += arr[i] + arr[j] ;
                i+=2;
                j+=2;
            }
            else {
                i++;
                j++;
            }
        }
        return ans ;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends