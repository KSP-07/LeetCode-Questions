//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
  void solve(vector<int> &A,  vector<vector<int>>&ans,   vector<int>&temp, int index, int target){
      //jab ek traversal krke last index pe ajay
      if(index==A.size()){
          //if target is 0 that means that we have some elements which combine to form the target
          if(target==0){
              ans.push_back(temp);
          }
          return;
      }
      
      //picking up the element
      if(A[index]<=target){
          //adding element to the array
          temp.push_back(A[index]);
          solve(A,ans,temp,index,target-A[index]);
          //after reaching if it comes to this step that means one way has been tried with the particular value and now we have to make space to try to use another value
          temp.pop_back();
      }
      
      //not picking an element
      solve(A,ans,temp,index + 1,target);
      
  }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        int n = A.size();
        
        //sorting and removing duplicates
        sort(A.begin() , A.end());
        //removing duplicates because duplicates will cause duplicates in the ans
         A.erase(unique(A.begin(),A.end()),A.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(A,ans,temp,0,B);
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends