//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A , A+n);
        
        for(int i = 0 ; i < n ; i++ ) {
            int left_sum = X - A[i] ;
            
            for(int j = i+1 , k = n-1 ; j<k ; ){
                if( A[j] + A[k] == left_sum) return true;
                else if(A[j] + A[k] < left_sum) j++;
                else k--;
            }
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends