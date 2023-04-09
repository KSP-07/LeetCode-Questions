class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int len = colors.size();
        
        vector<int> adj[len];
        vector<int> indegree(len);  //do not initalise with 0 as in case of empty array will give runtime
        
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for(int i=0; i<len; i++){
            if(indegree[i]==0) q.push(i);
        }
        // unordered_map<char , int> mp;
        // for(int i = 0 ; i<len ;i++){
        //     mp[colors[i]] = i;
        // }
        
        unordered_map<int , int> freq;   //why not this
        
        vector<vector<int>> dp(len , vector<int>(26,0));
        
        
        int maxi = 0;
        int cnt =0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front(); q.pop();
                 dp[node][colors[node]-'a']++;    //curr node is visited so adding 1 to freq
               maxi = max(maxi , dp[node][colors[node]-'a']);
                // freq[colors[node]]++;
                // cout<<freq[colors[node]]<<" "<<node<<" "<<colors[node]<<endl;
                cnt++;
                for(auto i: adj[node]){
                    for (int k = 0; k < 26; k++) {
                    // Try to update the frequency of colors for neighbor to include paths
                    // that use node->neighbor edge.
                        dp[i][k] = max(dp[i][k], dp[node][k]);
                    }

                    indegree[i]--;
                    
                    if(indegree[i]==0){
                        q.push(i);
                    }
                }
            }
        }
        if(cnt != len) return -1;

        return maxi;
        
    }
};