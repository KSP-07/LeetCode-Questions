//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
    
    //we are using bfs algorithm here coz , it will visit all posible paths form the pos it is currently standign then it's child wise , 
    //so ans could be found in step one only , dfs will move to other pos then other so it will not check that it could reach the asn from curr position
    
    //we are storing the curr pos in queue , checking if it's ans , then taking all movements from curr pos , pushing in q , and also checking 
    //if any position holds the ans
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    if(KnightPos == TargetPos) return 0;   //if pos is same as target pos then simply return
	    
	    //these are the moves that knight can take from any position
	    int xmove[] = { 1 , 1 , -1 , -1 , 2 , 2 ,-2 , -2};
	    int ymove[] = { 2 , -2 , 2 , -2 , 1 , -1 ,1 , -1};
	    
	    vector<vector<int>> vis(N , vector<int>(N,0));
	    
	    queue<pair<int , pair<int ,int>>> q;
	    
	    int x1=KnightPos[0] -1 , y1 = KnightPos[1]-1 ;
	    
	    int tx = TargetPos[0] -1, ty= TargetPos[1]-1;
	    
	    q.push({0 , { x1 , y1 }});   //pushing the curr pos into the queue
	    vis[x1][y1]=1;   //since we visited the curr pos , we marked it true
	    
	    
	    while(!q.empty()){
	        auto it = q.front();
	        q.pop();
	        
	        int steps =  it.first;
	        int row = it.second.first;
	        int col = it.second.second;
	        
	        if(row==tx && col == ty) return steps;   //checinkg ki ans milgya ki nhi
	        
	        //now since this pos was not ans , we move in all 8 direction to check , we use loop to avoid doing it manually
	        for(int i=0;i<8;i++){
	            //curr pos se 8 directions mai move kr rhe aur valid pos push kr rhe q mai 
	            //aur jo push kr rhee usse vis mark krderhe isliye dobara visit na ho kahi aur se ghumke aake
	            int nrow = row + xmove[i];
	            int ncol = col + ymove[i];
	            
	            if(nrow>=0 && ncol >=0 && nrow<N && ncol<N && !vis[nrow][ncol]){
	                q.push( {steps +1 , {nrow , ncol}} );
	                vis[nrow][ncol]=1;
	            }
	        }
	    }
	    
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends