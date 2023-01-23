//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
    //two appraoches: 1->Using priority queue , 2-> Using two pointers
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	//can be solved using min priority queue ,with dept as first and arrival as second , then will compare with top element
    	//sorting both array to use two pointer approach
    	
    	//dono sort krke pointer rkhdenge...arrival aur dept pe , ab dekh lenge ki arrival horha aur uss tym dept ka status kya hai
    	//agar dept kam hua to mtlb naya pt nhi chiye...dono increment kr jayge...nhi to arrival wala wit pt+1
    	
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int platforms=1 , i=1,j=0;   //i wala arrival pe rkh rhe aur j wala dep pe
    	
    	while(i<n){
    	    if(arr[i] <=dep[j]){
    	        platforms++;
    	    }else{
    	        j++;  //naye pt ki jrurat nhi, j ka dept tym hochuka mtlb... ab sirf agla chck hoga
    	    }
    	    i++;   //har iteration pe ek train ka arrival horhaa...
    	}
    	return platforms;
    }
};






//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends