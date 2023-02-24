class Solution {
public:
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
    }
};