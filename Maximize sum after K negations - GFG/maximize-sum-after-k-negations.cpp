//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        
        //greedy sochke...sort kr rhee..taaki jo max value de ske neg v=number wo phle aajay
        sort(a ,a+n);
        
        //ab iterate kre negative numbers flip kr rhee
        for(int i=0;i<n;i++){
            if(a[i]<0 && k>0){
                a[i]=a[i]*-1;
                k--;
            }
        }
        long long sum=0;
        for(int i=0;i<n;i++) sum+=a[i];
        
        //ab agar k bach gaya, humara array ab +ve bann chuka hai to ab sirf ek flip krna hoga agr odd bcha hai k
        //agar k even hai to flip krne ka koi fayda nhi
        int x = *min_element(a , a+n);
        
        if(k&1) sum-=2*x;   //two se isliye kr kr rhee kuki ek baar wo sum mai add hochuka hai aur ab ek baar minus bhi krna tha
        return sum;
        
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends