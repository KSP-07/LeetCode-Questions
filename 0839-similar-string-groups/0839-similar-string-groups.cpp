class Solution {
public:
    
    
    bool similar( string &s1 , string &s2 ){
        int different = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i]) different++;
        }
        return (different == 0 || different == 2);
    }
    
   /* 
    void dfs ( vector<vector<int>> &adj , vector<int> &vis , int node){
        vis[node] = 1 ;
        
        for( auto i : adj[node]){
            if( !vis[i]){
                dfs(adj , vis , i);
            }
        }
    }
   */ 
    
    int findParent( vector<int> &parent , int node ){
        if( parent[node] == node ) return node;
        
        return parent[node] = findParent( parent , parent[node] );
    }
    
    bool merge( vector<int> &parent , int i , int j ){
        int parent1 = findParent( parent , i);
        int parent2 = findParent( parent , j);
        
        if( parent1 == parent2 ) return false;
        
        parent[ parent1] = parent2;
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size() ;
       /* 
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (similar(strs[i], strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n , 0);
        int cnt = 0;
        for( int i = 0 ; i < n ; i++ ){
            if( !vis[i]){
                cnt++;
                dfs(adj , vis , i);
            }
        }
        return cnt;
        */
        
        
        vector<int> parent(n);
        int conn_comp = n;
        
        for(int i = 0 ; i < n ; i++ ) parent[i] = i;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (similar(strs[i], strs[j]))
                {
                    bool hasMerged = merge(parent , i , j );
                    if( hasMerged ) conn_comp--;
                }
            }
        }
        return conn_comp;
    }
};