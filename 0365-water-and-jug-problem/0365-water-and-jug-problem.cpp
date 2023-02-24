class Solution {
public:
    //dfs app
    /*
   bool dfs(int x, int y, int z, int m, int curr, vector<int> &vis)
    {
        if (curr < 0 || curr > m || vis[curr] == 1)
            return false;
        if (curr == z)
            return true;
        vis[curr] = 1;
        bool a = dfs(x, y, z, m, curr + x, vis);
        bool b = dfs(x, y, z, m, curr - x, vis);
        bool c = dfs(x, y, z, m, curr + y, vis);
        bool d = dfs(x, y, z, m, curr - y, vis);
        return a || b || c || d;
    }
    
    */
    bool canMeasureWater(int x, int y, int t) {
        //math solution
        /*
        if(x+y ==t || x==t || y==t) return true;
        if(x+y<t) return false;
        
        int d = gcd(x, y);
        // cout<<t<<" "<<d<<endl;
        return (t%d==0);
        */
        
        //bfs approach
        if(x+y ==t || x==t || y==t) return true;
        if(x+y<t) return false;
        
        int max_cap = x + y;
        queue<int> q;
        q.push(0);
        
        vector<int> vis(max_cap+1 , 0);
        vis[0]=1;
        vector<int> move= {x , -x , y ,-y};
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            if(curr == t) return true;
            
            for(auto i:move){
                int k = i + curr;
                
                if(k>=0 && k<=max_cap && !vis[k]){
                    q.push(k);
                    vis[k]=1;
                }
            }
        }
        return false;
        
        /*
        DFS APPROACH
         if (x + y == z || x == z || y == z)
            return true;
        if (x + y < z)
            return false;
        int m = x + y; // max capacity
        vector<int> vis(m + 1, 0);
        return dfs(x, y, z, m, 0, vis);
        */
    }
};