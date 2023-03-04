//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void dfs(int i, int j , int xd , int yd , vector<vector<int>> &matrix , int n ,int m ,vector<vector<int>> &vis,int steps ,int &maxi){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || matrix[i][j]==0) return;
        
        if(i==xd && j==yd){
            maxi = max(maxi , steps);
            return;
        }
        vis[i][j]=1;
        dfs(i-1 , j , xd , yd , matrix , n ,m, vis , steps+1 , maxi);
        dfs(i+1 , j , xd , yd , matrix , n ,m, vis , steps+1 , maxi);
        dfs(i , j-1 , xd , yd , matrix , n ,m, vis , steps+1 , maxi);
        dfs(i , j+1 , xd , yd , matrix , n ,m, vis , steps+1 , maxi);
        
        vis[i][j]=0;
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        int n= matrix.size();
        int m = matrix[0].size();
        int maxi =-1;
        vector<vector<int>> vis (n , vector<int>(m,0));
        dfs(xs, ys , xd ,yd , matrix , n ,m , vis,0 ,maxi);
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends