//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:

    bool dfs(int node , vector<pair<int,int>> adj[] , vector<bool> &vis , int k , int cost){
        vis[node]=1;
        if(cost>=k) return true;
        
        for(auto i: adj[node]){
            int v = i.first;
            int wt = i.second;
            if(!vis[v]){
                if(dfs(v , adj , vis , k , cost+wt)) return true;
            }
        }
        vis[node] =0;
        return false;
    }
    
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
       //  Code Here
       vector<pair<int,int>> adj[V];
       for(int i = 0; i<E*3 ;i +=3){
           int u = a[i];
           int v= a[i+1];
           int wt = a[i+2];
           
           adj[u].push_back({v, wt});
           adj[v].push_back({u , wt});
           
       }
       
       vector<bool> vis(V ,0);
       return dfs(0 , adj , vis , k , 0);
    } 
};




//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends