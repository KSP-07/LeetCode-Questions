//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    bool check(int nx, int ny, int n, int m)
    {
        if(nx>=0 && nx<n && ny>=0 && ny<m) return true;
        return false;
    }
    int findShortestPath(vector<vector<int>> &mat)
    {
        int n=mat.size();
        int m=mat[0].size();

        vector<pair<int,int>> move ={{0,1} ,{0,-1},{1,0},{-1,0}};
        //marking non safe tiles
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==0)
                {
                    for(auto it: move)
                    {
                        int nx=i+ it.first;
                        int ny=j+ it.second;
                        if(check(nx,ny,n,m) && mat[nx][ny]!=0) mat[nx][ny]=-1;
                    }
                }
            }
        }
        //now since we want to use bfs, simply making -1 tiles also 0 as denied access
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==-1) mat[i][j]=0;
            }
        }
        
        //bfs traversal

        vector<vector<int>>dp(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        
        //pushing those starting values which can be used to visit
        for(int i=0; i<n; i++)
        {
            if(mat[i][0]!=0)
            {
                q.push({i,0});
                dp[i][0]=1;  //making their distance as 1 
            }
        }
        
        while(!q.empty())
        {
           int x=q.front().first;
           int y=q.front().second;
           int dis=dp[x][y];   //taking out distance that was required to visit the curr cell
           q.pop();
           for(auto it: move)
           {
               int nx=x+ it.first;
               int ny=y+ it.second;
               if(check(nx,ny,n,m) && dp[nx][ny]==-1 && mat[nx][ny]!=0)
               {
                   dp[nx][ny]=dis+1;  //adding one to the distance
                   q.push({nx,ny});
               }
           }
        }
        int ans=1e9;
   
        for(int i=0; i<n; i++)
        {
            //checking "last cell" , if it was visited , and finding min among them
            if(dp[i][m-1]!=-1) ans=min(ans,dp[i][m-1]);
        }
        if(ans==1e9) ans=-1;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends