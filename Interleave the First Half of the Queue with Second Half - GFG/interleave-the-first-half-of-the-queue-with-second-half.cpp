//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        int n = q.size() ;
        
        queue<int> qu ;
        
        for(int i = 0 ; i< n/2 ; i++ ){
            qu.push(q.front()) ; q.pop() ;
        }
        vector<int> ans ;
        
        while(!q.empty()) {
            ans.push_back(qu.front()) ; qu.pop() ;
            ans.push_back(q.front() ) ; q.pop() ;
        }
        
        return ans ;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends