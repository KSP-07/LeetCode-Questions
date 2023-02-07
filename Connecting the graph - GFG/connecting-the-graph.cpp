//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class DisjointSet{


    public:
        vector<int> rank , parent,size;
    //constructor of disjoint set
        DisjointSet(int n){
            rank.resize(n+1 , 0);   //n+1 so that it can be used for both n and n+1 indexing
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0; i <=n;i++){
                parent[i] = i;      //making each node parent of itself
                size[i]=1;
            }
        }

        //finding ultimate parent
        int findUpar( int node){
            if(node == parent[node]){
                return node;
            }

            //now doing path compression using backtracing by storing in parent[node] the result of the last 
            //recur call ie second last parent parent's
            return parent[node] = findUpar(parent[node]);   //using
        }

        //now combing the two components according to their rank
        void unionByRank(int u , int v){
            int ultP_u = findUpar(u);  //finding ultimate parent of u
            int ultP_v = findUpar(v);  //fnding ultimate parent of v

            if(ultP_u == ultP_v) return;  //is the parent are same then no need to do anything

            //agar u ke parent ki rank kam hai to u..p mai jaake lag jayga
            if(rank[ultP_u] < rank[ultP_v]){
                parent[ultP_u] = ultP_v;
            }
            //agr v ke parent ki rank kamhai to v..u mai jaake lag jayga
            else if(rank[ultP_v]< rank[ultP_u]){
                parent[ultP_v] = parent[ultP_u];
            }
            //agr same hai toh fir bss kisi mai bhi laga do aur uski rank bdaado
            else{
                parent[ultP_v] = ultP_u;
                rank[ultP_u]++;
            }
        }


        //now combing the two components according to their size
        void unionBySize(int u , int v){
            int ultP_u = findUpar(u);  //finding ultimate parent of u
            int ultP_v = findUpar(v);  //fnding ultimate parent of v

            if(ultP_u == ultP_v) return;  //is the parent are same then no need to do anything

            //agar u ke parent ki rank kam hai to u..p mai jaake lag jayga
            if(size[ultP_u] < size[ultP_v]){
                parent[ultP_u] = ultP_v;
                size[ultP_v] += size[ultP_u];
            }
            else{
                parent[ultP_v] = ultP_u;
                size[ultP_u] += size[ultP_v];
            }
        }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        
        DisjointSet ds(n);  //using disjoint set that will help to connect graph components dynamically and also used to check ultimate parent
        
        int cntExtras=0;     //to cnt extra edges btw nodes , as disjoint will connect nodes to one parent that node share , and thus there exist one path already if both nodes had same parent
        
        for(auto it:edge){
            
            //u aur v mai connection given hai , to phle sbko alag krlete hai fir union by size kr rhee aage agr parent same nhi hai
            //kuki , fir individual components sath mai krdega aur ek common node se connect hone lagege toh pata chlega ki path already tha
            int u = it[0];
            int v= it[1];
            
            //agar do nodes ke parent ke same hai toh fir already node se ek path hai unhe connect krne ke liye
            if(ds.findUpar(u) == ds.findUpar(v)) cntExtras++;
            
            //ultimate parent same nhi tha toh fir uninon krke ek common parent nikal aayga ab
            else ds.unionBySize(u , v);
        }
        
        //yaha pe components nikal rhee hai
        //nodes, jo khudke ultimate parent honge wo hii alag component baana skte hai
        //disjoint set ki help se parent array se pata chal jayga
        int conC=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) conC++;
        }
        
        int ans=conC-1;   //ab agr n components hai toh n-1 edges chiye hongi jodne ke liye
        
        if(cntExtras >= ans) return ans;  //agar extra edges ans ke jitni pdd rhii toh connect kr sktee
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends