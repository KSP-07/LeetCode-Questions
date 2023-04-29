class DisjointSet{
    public:
    vector<int> parent , size ;
    
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        
        for(int i = 0 ; i < n ; i++) parent[i] = i; 
    }
    
    int findUpar(int node){
        if(node == parent[node] ) return node;
        
        return parent[node] = findUpar(parent[node]);
    }
    
    void unionBySize( int u , int v ){
        int ult_u = findUpar(u);
        int ult_v = findUpar(v);
        if(ult_u == ult_v) return ;
        
        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u] ;
        }
        
        else{
            parent[ult_v] = ult_u ;
            size[ult_u] += size[ult_v] ;
        }
        
    }
};

class Solution {
public:
    static bool cmp( vector<int> &a , vector<int> &b){
        return a[2] < b[2] ;
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        
        //ye isliye kr rhee taaki ek kind of indexing bann jaay queries mai jispe hum ans mai val o true kr paaay
        for( int i = 0 ; i < queries.size() ; i++){
            queries[i].push_back(i);
        }
        
        vector<bool> ans(queries.size() , false);
        
        sort(queries.begin() , queries.end() , cmp);
        sort(edgeList.begin() , edgeList.end() , cmp);
        int j = 0;
        for(int i = 0 ; i < queries.size() ; i++){
            //unn vetices ka hii sath mai component bnega jisme limit ke niche ki val hogi...
            while( j < edgeList.size() && edgeList[j][2] < queries[i][2]){
                ds.unionBySize( edgeList [ j ][ 0 ] , edgeList [ j ] [ 1 ] ) ;
                j++;
            }
            //agr same component mai hue toh fir ans true hojayga
            if(ds.findUpar(queries[i][0]) == ds.findUpar(queries[i][1]) ) ans[queries[i][3]] = true;    //queries[i][3] ye extra add krra thaa isilye ki ans modify krle easily
        }
        return ans;
    }
};







