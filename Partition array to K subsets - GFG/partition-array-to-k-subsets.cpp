//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
 bool solve(int a[],int sum,int part,int k,bool vis[],int index,int n)
    {
        if(k==0) return true;
        if(sum>part) return false;
        if(sum==part) {
            return solve(a,0,part,k-1,vis,0,n);
        }


      
      //ek element ko lega , fir agr toh sum target se jada hua toh backtrack krega , agr jada nhi hue toh ek wo ekements leke sab try krelga
      //fir bhi nhi hua ,to curr element bhi pop krke fir usko chorke check krega
      //for ex...2 , 1 add hoga , toh 4 se leke 6 tkk nhi bngea aur pop hote rhenge wo aake , fir 1 se leke bhi koi nhhi bana tha
      //toh fir 1 ko bhi hata ke krenge
      for(int i=index;i<n;i++)
        {
            if(vis[i]) continue;
            
            vis[i]=true;
            if(solve(a,sum+a[i],part,k,vis,i+1,n)) return true;
            
            vis[i]=false;
        }
        return false;
    }
        
   bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum = 0;
         for(int i=0;i<n;i++)
         {
             sum+=a[i];
         }
         
         if(sum%k!=0) return false;
         
         bool vis[n] = {false}; // to find unique subsets !!!
         
         return solve(a,0,sum/k,k,vis,0,n);
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
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends