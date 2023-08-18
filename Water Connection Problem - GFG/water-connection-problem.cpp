//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    void dfs(int node , int &end , int &mini , int vis[] , vector<pair<int,int>> adj[]){
        vis[node] = 1;
        
        for(auto i : adj[node]){
            if(!vis[i.first]){
                end = i.first;
                mini = min(i.second , mini);
                
                dfs(i.first , end , mini , vis , adj);
            }
        }
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        int vis[n+1] = {0};
        
        vector<int> in(n+1 , 0) , out(n+1 , 0);
        
        vector<pair<int,int>> adj_list[n+1];
        
        for(int i = 0 ; i < p ; i++ ){
            in[b[i]] = 1;
            out[a[i]] = 1;
            
            adj_list[a[i]].push_back({b[i] , d[i]});
            
        }
        
        vector<vector<int>> ans;
        
        for(int i = 1 ; i <= n ; i++) {
            if(in[i] == 0 && out[i] == 1 && vis[i] == 0){
                
                int s = i ;
                int e ;
                int min_width = INT_MAX;
                
                dfs(s , e , min_width , vis , adj_list);
                
                ans.push_back({s , e , min_width}) ;
            }
        }
        
        return ans ;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends