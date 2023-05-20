class Solution {
public:
    
    void dfs(string &src , string &end , unordered_map<string, vector<string>> &graph , unordered_map<string,int> &vis ,
            unordered_map<string , double> &mp , double &val , bool &flag){
        
        vis[src] =1;
        if(flag == true) return;
        
        for(auto i : graph[src]){
            if(!vis[i]){
                val *= mp[src + "->" + i];
                if(end == i){
                    flag = true;
                    return;
                }
                
                dfs(i , end , graph , vis , mp , val , flag);
                if(flag == true) return;
                
                else{
                    val /= mp[src + "->" +i];   //it is a important step
                }
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string , double> mp;
        unordered_map<string ,vector<string>> graph;
        int sizeOfEq = equations.size();
        
        for(int i = 0 ; i < sizeOfEq ; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            
            mp[ u + "->" + v] = values[i];
            mp[ v + "->" + u ] = 1 / values[i] ;
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(auto i: queries){
            string u = i[0];
            string v = i[1];
            
            if(graph.find(u) == graph.end() || graph.find(v) == graph.end()){
                ans.push_back(-1);
            }
            
            else{
                double val = 1.0;
                bool flag = false;
                unordered_map<string, int> vis;
                
                if(u == v) flag = true;
                else{
                    dfs(u , v , graph , vis , mp , val , flag);
                }
                
                if(flag) ans.push_back(val);
                else ans.push_back(-1);
            }
        }
        return ans;
    }
};