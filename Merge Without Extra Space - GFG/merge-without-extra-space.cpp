//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            // //Mehtod1 : T:O(n*m) S:O(1)
            // int i=0;
            // while(i<n)
            // {
            //         if(arr2[0]<arr1[i])
            //         {
            //             swap(arr2[0],arr1[i]);
            //         // the new arr1[i] will be less than arr1[i+1] as, already arr2[0] was less
            //          // than old arr1[i], and the arr1[i+1] was greater than old arr1[i].
            //          // But, NOTE:
            //          // Now the new value at arr2[0] may not be at the right place in the 
            //          //   previously sorted arr2.
                     
            //          long long k=arr2[0];
            //          //place arr2[j] at right palce by shifting in the arr2.
            //          int j1=1;
            //          while(k>=arr2[j1] && j1<m)
            //          {
            //               arr2[j1-1]=arr2[j1];
            //               j1++;
            //          }
            //           arr2[j1-1]=k; //DON't forget -1, as before failure condition j1 was increment,
            //         }
            // i++;
            // }
            
            int i=n-1 , j=0;
            while(i>=0 && j<m){
                if(arr2[j]<=arr1[i]){
                    swap(arr2[j],arr1[i]);
                    i--;
                    j++;
                }
                else{
                    j++;
                }
            }
            sort(arr1 , arr1 + n);
            sort(arr2 , arr2 + m);
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends