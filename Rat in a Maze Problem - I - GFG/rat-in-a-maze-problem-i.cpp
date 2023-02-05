//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    //we will call dfs in all directions and if any reaches the end , we will store that one in ans
    
    void dfs(int i , int j , string s , auto &m, int n , auto& vis , auto &ans){
        if( i<0 || i>=n || j<0 || j>=n) return;   //edge case , if i and j are at borderes
        if(m[i][j] == 0 || vis[i][j]==1) return; //edge case that is path is blocked or the node is already visited then we do no need to visit it anymore 
        
        if(i==n-1 && j==n-1){
            ans.push_back(s);   //this means that one of the ans is found
            s="";
            return;
        }
        
        //classis dfs...making node visited first then calling recursion in sorted way so we do not have to do it afterwards
        vis[i][j]=1;
        
        dfs(i+1 , j , s+'D', m , n , vis , ans);
        dfs(i , j-1 , s+'L', m , n , vis , ans);
        dfs(i , j+1 , s+'R', m , n , vis , ans);    
        dfs(i-1 , j , s+'U', m , n , vis , ans);
        
        vis[i][j]=0;    //We are making node unvisited so that other function call use that for the next time ;) not because there is no path.
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        int size=m.size();
        vector<vector<int>> vis(size, vector<int>(size,0));   //creating a 2-D visted array
        
        //edge cases ATQ
        if(m[0][0]==0) return ans;
        if(m[n-1][n-1]==0) return ans;
        
        string s="";
        
        dfs(0,0,s ,m ,n , vis ,ans);
        
        return ans;
    }
    
    
    /*
    class Solution{
    public:
    void help(vector<vector<int>>&arr,int n , int i,int j,string temp
    ,vector<string>&ans,vector<vector<bool>>visited){
        if(i<0||j<0||i>=n||j>=n){
            return ;
        }
        if(visited[i][j]){
            return ;
        }
        if(arr[i][j]==0){
            return ;
        }
        visited[i][j]=true;
        if(i==n-1&&j==n-1){
         ans.push_back(temp);
         return ;
        }
        
        help(arr,n,i+1,j,temp+'D',ans,visited);
        help(arr,n,i,j+1,temp+'R',ans,visited);
        help(arr,n,i-1,j,temp+'U',ans,visited);
        help(arr,n,i,j-1,temp+'L',ans,visited);
        
    }
    vector<string> findPath(vector<vector<int>> &arr, int n) {
        // Your code goes here
         vector<string> ans;
         string temp="";
         vector<vector<bool>> visited(n,vector<bool>(n,false));
         help(arr,n,0,0,temp,ans,visited);
         return ans;
    }
};

    */
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends