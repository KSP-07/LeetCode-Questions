//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int> mp;
        for(auto i : s ){
            mp[i]++;
        }
        
        priority_queue<int> pq;
        
        for(auto i:mp){
            pq.push( i.second );
        }
        
        while(k--){
            int val = pq.top(); pq.pop();
            val--;
            pq.push(val);
        }
        
        int ans = 0;
        while(!pq.empty()){
            int val = pq.top(); pq.pop();
            ans+= (val*val);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends