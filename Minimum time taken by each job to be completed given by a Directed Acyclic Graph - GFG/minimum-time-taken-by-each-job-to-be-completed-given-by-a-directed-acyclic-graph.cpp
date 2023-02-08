//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    //topological sort type ka use hoga
    //here using bfs for topological sort
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            // code here
            
            //creating adjancey list fromm edges given
            vector<int> adj[n];   //syntax for creating vector of vectors
            vector<int> in(n, 0);
            
            for(int i=0;i<m;i++){
                adj[ edges[i][0]-1 ].push_back(edges[i][1] -1 );   //-1 indexing ki vjh se kr rhee hai
                in[edges[i][1]-1]++;
            }
            
            //hum u->ek node ki value smlo..usse push krenge aur kitne steps lag gaye usse hone mai
            queue<pair<int , int>> q;
            
            //jinki indegree 0 hai wo push kr rhe phle kuki wo kisi pe depend nhi hai
            for(int i=0;i<n;i++){
                if(in[i]==0){
                    q.push({i,1});   //mtlbb ki ith node ka kaam sbse phle hua to usse bss 1 unit time laga
                }
            }
            
            vector<int> topo(n);   //ek vec lerhe jisme hum node ko index ki trh rkh ke tym note krenge...key pair types
            
            while(!q.empty()){
                int node = q.front().first;
                int steps = q.front().second;
                q.pop();
                
                topo[node] = steps;   //jo bhi node q mai jaarhi hai...mtlb uska kaam krne ke tym yani steps nikal aaya hoga
                
                for(auto i: adj[node]){
                    in[i]--;   //ab jo node visit horhii..mtlb ek parent gaya to ab dependecy kam hogyy
                    
                    //agr ab indegree 0 hogyy toh bss fir uska tym aagya...ab line se push hote jayge jiska khtm hoga..aur q mai isliye kr rhee
                    //kuki wo bhi to kisi ke parent hosktee...to unke bcho ko bhi to visit krna pdd skta
                    if(in[i]==0){
                        q.push({i, steps+1});   //step mai 1 isliye add kr rhee kuki abi tkk yaha aane ke x step thee..ab iss kaam ko krne ka 1 unit aur lagega na
                    }
                }
            }
            return topo;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends