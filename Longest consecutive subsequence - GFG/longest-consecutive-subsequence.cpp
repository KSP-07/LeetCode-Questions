//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_map<int,int> mp;
      int max_element = 0;
      for(int i = 0 ; i < N ; i++ ){
          mp[arr[i]]++;
          max_element = max (max_element , arr[i]);
      }
      int maxi_cnt = 0 ;
      int temp_cnt = 0 ;
      for(int i =0 ; i <= max_element ; i++ ){
          if(mp[i]){
              temp_cnt++;
          }
          else temp_cnt = 0;
          
          maxi_cnt = max(maxi_cnt , temp_cnt );
      }
      
      return maxi_cnt ;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends