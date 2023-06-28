class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        if(start ==  end) return 1;
        
        vector<pair<int , double>> adj[n];
        int m = edges.size();
        
        //creating adj matrix
        for(int i =0 ; i< m ; i++){
            double prob = succProb[i];
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back({ v , prob});
            adj[v].push_back({u , prob});
        }
        
        priority_queue<pair<double, int>> pq;
        pq.push({1.0 , start});
        
        vector<double> prob(n , 0);
        prob[start] = 1;
        
        while(!pq.empty()){
            auto top = pq.top() ; pq.pop();
            double curr_p = top.first;
            int node = top.second;
            
            if(node == end) return curr_p;
            
            for(auto &i : adj[node]){
                int adj_node = i.first;
                double P = i.second;
                
                if(prob[adj_node] < P*curr_p){
                    prob[adj_node] = P*curr_p;
                    pq.push({P*curr_p , adj_node});
                }
            }
        }
        return 0;
    }
};