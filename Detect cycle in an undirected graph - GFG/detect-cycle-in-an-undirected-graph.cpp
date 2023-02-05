class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    //using bfs with help of visited node array
    
    //isme kya kr rhe hai aur ku?
    //since graph may not be connected , sbbi node pe traverse krenge jo vis nhi hue ki wha se cycle ban rha kya
    //detect kaise kree---> ek vis array bnni hue hai , ab since mai levelwise traverse kr rhaa huu , agr koi aur node phle visit hue
    //jo ki parent node bhi nhi hai toh cycle bnnn rhii kuki same node ko do raste se ghumke access kr paarhe
    //iske liye simple bfs traversal krenge pr sath mai pair ka use krke parent bhi store krte rhenge,taki check kr paay
    bool detect(int src , vector<int> adj[] , vector<int>&vis){
        vis[src]=1;
        queue<pair<int,int>> q;   //src index ka pata rkhne ke liye pair mai lia
        q.push({src , -1});  //starting index -1 dedi
        while(!q.empty()){
            int first = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto i:adj[first]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push({i ,  first});   //then node and the parent
                }
                else if(parent!=i){    //level wiese traverse kr rhe thee...aur koi node phle hii visit kr chuka aur wo parent node bhi nhi toh bss fir cycle
                    return true;
                }
            }
        }
        return 0;
    }
    
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0; i<V;i++){
            if(!vis[i]){
                if(detect(i , adj , vis)) return true;
            }
        }
        
        return false;
    }
    
    
    /*
    using dfs algo and same parent concept
    
    bool detect(int src , int parent , auto &adj , auto &vis){
        vis[src]=1; //updating the visited array for the curr node
        for(auto i:adj[src]){   //visiting neighnours of curr node
            if(!vis[i]){
                if( detect(i , src, adj , vis ) return true;   //agr ans iss nayi node pe milta to return krdia
            }
            else if(i!=parent) return true;   //ab ek node visit ho chuki phle , dusre raaste se toh cycle hai
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]){
    
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if( detect(i , -1, adj , vis ) return true;
            }
        }
        return false;
    }
    
    */
};
