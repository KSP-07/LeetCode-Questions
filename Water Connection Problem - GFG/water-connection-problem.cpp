//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
    
    void dfs(int node , vector<pair<int,int>> adj_list[], int &min_width,int &end,int vis[]){
        vis[node]=1;   //yaha pe jo node visit kr rhee usse true set kr derhe
        for(auto x: adj_list[node]){
            if(vis[x.first]==0){   //if the neighbour node is not visited
                end=x.first;       //this is incoming house(b[i] wali value)
                min_width= min(min_width , x.second);   //taking min diameter possible
                //ab ek neighbour hogya , to ab iss node se kinti aur visit kr skte , isliye dfs call
                dfs(x.first , adj_list , min_width , end , vis);
            }
        }
    }
class Solution
{
    public:
    
    //using dfs graph traversal as it will form different disconnected graph components
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        int vis[n+1];      //to keep track of visited nodes..n+1 bcoz tanks and pipes will begin from 1
        
        vector<vector<int>> ans;   //to store ans...it is vector of vector which means each row will be vec to store any number of elements of var column size
        memset(vis, 0 , sizeof(vis));   
        vector<int>in(n+1,0);   //to store house number with incoming pipe
        vector<int> out(n+1,0);  //to store house number with outgoing pipe
        
        vector<pair<int,int>> adj_list[n+1];  //adjancy list to store the neighbour elements
        
        //now marking the houses with incoming pipe and creating adjancey list
        for(int i=0;i<p;i++){
            out[a[i]]=1;
            in[b[i]]=1;
            //we have pipe that goes from a[i] to b[i]
            adj_list[a[i]].push_back({b[i],d[i]});
        }
        
        for(int i=1;i<=n;i++){
            if(in[i]==0 && out[i]==1 && vis[i]==0){   //mtlb jisme incoming nhi hai pr outgoing hai..means tank wala ghr
                int s=i;
                int e;
                int min_width=INT_MAX;
                dfs(s,adj_list , min_width ,e , vis);
                ans.push_back({s,e,min_width});
            }
        }
        return ans;
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