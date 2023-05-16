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
      /*
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
      */
      
      int n = a.size();
        int small_sum = a[0];
        int curr_sum = a[0];
        for(int i=1;i<n;i++)
        {
            if(curr_sum >= 0)
            {
                curr_sum = a[i];
            }
            else curr_sum += a[i];
            small_sum = min(small_sum, curr_sum);
        }
        // small_sum = min(small_sum, curr_sum);
        return small_sum;
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