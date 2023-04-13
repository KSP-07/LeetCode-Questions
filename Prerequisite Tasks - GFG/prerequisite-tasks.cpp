//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// class Solution {
// public:
// //this qstn is same as Minimum time taken by each job
// 	bool isPossible(int n, vector<pair<int, int> >& pre) {
// 	    // Code here
	    
	    
// 	    vector<int> adj[n];
// 	    vector<int> in(n , 0);
	    
// 	    for(auto i:pre){
// 	        adj[i.first].push_back(i.second);
// 	        in[i.second]++;
// 	    }
	    
// 	   // for(int i=0;i<n;i++){
// 	   //     for(int it:adj[i])
// 	   //         in[it]++;
// 	   // }
	    
// 	    queue<int> q;
	    
// 	    for(int i=0;i<n;i++){
// 	        if(in[i]==0) q.push(i);
// 	    }
// 	    if(q.empty()) return false;
	    
// 	    int cnt=0;
// 	    while(!q.empty()){
// 	        int node= q.front();
// 	       // int steps = q.front().second;
// 	        q.pop();
	        
// 	        cnt++;
	        
// 	        for(auto i: adj[node]){
// 	            in[i]--;
// 	            if(in[i]==0){
// 	                q.push(i);
// 	            }
// 	        }
// 	    }

// 	  return cnt==n;
// 	}
// };


class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	    vector<int> indegree(N) , adj[N];
	    
	    for(auto i : prerequisites){
	        adj[i.second].push_back(i.first);
	        indegree[i.first]++;
	    }
	    
	    queue<int> q;
	    for(int i= 0 ; i<N;i++){
	        if(indegree[i] == 0) q.push(i);
	    }
	    int cnt = 0;
	    while(!q.empty()){
	        int node = q.front(); q.pop();
	        
            cnt++;
	        for(auto v : adj[node]){
	            indegree[v]--;
	            if(indegree[v]==0){
	                q.push(v);
	            }
	        }
	    }
	    
	    if(cnt==N) return true;
	    
	    return false;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
