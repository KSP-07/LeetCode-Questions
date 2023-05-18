
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> indegree(n);
        for(auto i : edges){
            int u = i[0];
            int v  = i[1];
            
            indegree[v]++;
        }
        for(int i = 0 ; i<n ; i++){
            if(indegree[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};