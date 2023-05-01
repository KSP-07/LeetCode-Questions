class DisjoinSet{
    public:
    vector<int> parent , size;
    
    DisjoinSet(int n ){
        size.resize(n , 1);
        parent.resize(n);
        for(int i = 0 ; i < n ; i++ ){
            parent[i] = i ;
        }
    }
    
    int findPar(int node ){
        if(node == parent[node]) return node;
        
        return parent[node] = findPar(parent[node]) ;
    }
    
    void UnionBySize(int u , int v){
        int ult_u = findPar(u) ;
        int ult_v = findPar(v) ;
        
        if(ult_u == ult_v) return;
        
        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u] ;
        }
        else{
            parent[ult_v] = ult_u ;
            size[ult_v] += size[ult_u];
        }
    }
    
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjoinSet Alice(n+1) , Bob(n+1);
        int ExtraCnt = 0 , Aedges = 0 , Bedges = 0;
        for(auto i : edges){
            // cout<<i[2]<<"here\n";
            if( i[0] == 3 ){
                
                Aedges++;
                Bedges++;
                // cout<<Aedges<<" "<<Bedges<<endl;
                if(Alice.findPar(i[1]) == Alice.findPar(i[2]) || Bob.findPar(i[1]) == Bob.findPar(i[2]) ){
                    ExtraCnt++;
                }
                else{
                    Alice.UnionBySize(i[1] , i[2]) ;
                    Bob.UnionBySize(i[1] , i[2]) ;
                }
                
            }
        }
        for(auto i : edges){
            int type = i[0];
            int u = i[1] ;
            int v = i[2] ;

            if(type == 1){
                Aedges++;
                if(Bob.findPar(u) == Bob.findPar(v)) ExtraCnt++;
                else Bob.UnionBySize(u , v) ;
            }
            if(type == 2){
                Bedges++;
                if(Alice.findPar(u) == Alice.findPar(v)) ExtraCnt++;
                else Alice.UnionBySize(u,v);
            }
            // Tedges++;
        }
        // cout<<ExtraCnt<<endl;
        int comp=0 , comp2=0;
        for(int i = 1 ;i<=n ; i++){
            if(Alice.findPar(i) == i ) comp++;
            if(Bob.findPar(i) == i ) comp2++;
        }
        if(comp > 1 || comp2>1) return -1;
        
        return  ExtraCnt;
    }
};



