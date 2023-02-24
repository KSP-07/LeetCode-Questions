//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
int minSteps(int m, int n, int d)
	{
	    vector<vector<int>> visited(m+1, vector<int> (n+1,0));
	    queue<pair<int,int>> q;
	    q.push({0,0});
	    int steps=0;
	    visited[0][0]=1;
	    
	    while(!q.empty())
	    {
	        int sz=q.size();
	        for (int i=0; i<sz; i++)
	        {
	            int x = q.front().first;
	            int y = q.front().second;
	            q.pop();
	            
	            //check if quanity required mesaured
	            if (x==d || y==d)
	            {
	                return steps;
	            }
	            
	            //empty jug A
	            if (x>0 and !visited[0][y])
	            {
	                q.push({0,y});
	                visited[0][y]=1;
	            }
	            
	            //empty jug B
	            if (y>0 and !visited[x][0])
	            {
	                q.push({x,0});
	                visited[x][0]=1;
	            }
	            
	            //fill jug A
	            if (x<m and !visited[m][y])
	            {
	                q.push({m,y});
	                visited[m][y]=1;
	            }
	            
	            //fill jug B
	            if (y<n and !visited[x][n])
	            {
	                q.push({x,n});
	                visited[x][n]=1;
	            }
	            
	            //Pour jug B ---> jug A
	            if (m-x>0 and y>0)
	            {
	                if (x+y<m and !visited[x+y][0])
	                {
	                    q.push({x+y,0});
	                    visited[x+y][0]=1;
	                }
	                else if (x+y>m and !visited[m][y-(m-x)])
	                {
	                    q.push({m, y-(m-x)});
	                    visited[m][y-(m-x)]=1;
	                }
	            }
	            
	            //Pour jug A ---> jug B
	            if (x>0 and n-y>0)
	            {
	                if (x+y<n and !visited[0][x+y])
	                {
	                    q.push({0,x+y});
	                    visited[0][x+y]=1;
	                }
	                else if (x+y>n and !visited[x-(n-y)][n])
	                {
	                    q.push({x-(n-y), n});
	                    visited[x-(n-y)][n]=1;
	                }
	            }
	        }
	        steps++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends