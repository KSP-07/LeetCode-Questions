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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtras=0;
        for(auto it: connections){
            int u=it[0];
            int v= it[1];
            
            if(ds.findUpar(u) == ds.findUpar(v)) cntExtras++;
            else ds.unionBySize(u , v);
        }
        
        int cntC=0;
        for(int i=0;i<n;i++){
//agar i apna khud ka parent hua iska mtlb wo kisi ka sub ni hai , to suru mai sbb khudke parent thee , fir union hua agr uske baad bhi hai to wo alag hue na
            if(ds.parent[i]==i) cntC++;
        }
        
        int ans = cntC-1;
        if(cntExtras>=ans) return ans;
        return -1;
    }
};
