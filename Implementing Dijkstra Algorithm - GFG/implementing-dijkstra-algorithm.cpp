//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        //creating a distance vector--> to store the dist of elements from the source vertex
        vector<int> distance(V , INT_MAX);
        
        //we want to take smaller distances first, so stroing them in min heap with dist and the node value
        priority_queue<pair<int,int> ,vector<pair<int,int>> ,  greater<pair<int,int>>> pq;   //creates a pq for min heap in pair

        pq.push({ 0 ,S}); //dist is zero because dist from  src to src is nothing
        distance[S]=0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            
            pq.pop();
            
            //now visiting neighbours
            for(auto v: adj[node]){
                //agar jo neighbour node hai , uska distance...src se iss element tkk ke prev distance se kam hai toh
                if( dist + v[1] < distance[v[0]] ){
                    distance[v[0]] = dist + v[1];
                    
                    //ab jab curr node ke nieghbour visit hogyyya...to ab distance kam mila iss niehbour node ko visit krne ka tbbi isme aay
                    //toh ab isko q mai rkha , agr ye sbse min hua toh ab iske neighbor dekhe jayge agli baar
                    pq.push({distance[v[0]] , v[0]});
                }
            }
        }
        return distance;
        
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends