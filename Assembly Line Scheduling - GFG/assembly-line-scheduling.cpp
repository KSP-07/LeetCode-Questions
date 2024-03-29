//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++



class Solution{
  public:
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
      //Code Here
      int n = a[0].size() ;
      vector<vector<int>> dp( 2 , vector<int> (n +1, INT_MAX));
      
      //adding intial cost
      /*
      with space
      
      dp[0][0] = a[0][0] + e[0];   
      dp[1][0] = a[1][0] + e[1];
      */
      int first = a[0][0] + e[0];
      int second = a[1][0] + e[1];
      
      //adding ending cost directly into the input array
      a[0][n-1] += x[0];
      a[1][n-1] += x[1];
      
      for(int i = 1 ; i < n ; i ++ ){
          int up = min ( first + a[0][i]  ,  second + a[0][i] + T[1][i]);
          int down = min (second + a[1][i]  ,  first + a[1][i] + T[0][i]);
          
          first = up ;
          second = down;
      }
    //   for(auto i: dp){
    //       for(auto j : i){
    //           cout<<j<<" ";
    //       }
    //       cout<<endl;
    //   }
      
    //   return min ( dp[0][n-1] , dp[1][n-1]);
    return min(first , second);
  }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(2,vector<int>(n)), T(2,vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>T[i][j];
            }
        }   
        vector<int> e(2), x(2);
        for(int i=0;i<2;i++){
            cin>>e[i];
        }
        for(int i=0;i<2;i++){
            cin>>x[i];
        }
        
        Solution ob;
        int ans = ob.carAssembly(a,T,e,x);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends