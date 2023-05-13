//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      //Code here
      int n = a.size();
      int ans = INT_MAX;
      int t_ans = 0;
      int neg = 0 , pos =0;
      for(int i = 0 ; i< n; i++){
          if(a[i] <0 ) {
              neg++;
              break;
          }
      }
      
      if(neg){
          for(int i = 0 ; i < n ; i++){
              t_ans += a[i];
              
              ans = min(ans , t_ans);
              if(t_ans >0) t_ans = 0;
          }
      }else{
          return *min_element(a.begin() , a.end());
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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends