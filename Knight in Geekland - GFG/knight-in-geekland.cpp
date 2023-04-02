//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int knightInGeekland(int x,int y,vector<vector<int>> &arr){
        // Code here
        queue<pair<int,int>> q;
        q.push({x ,y});
        vector<int> coins; 
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));
        vis[x][y]=1;
        // int coins=arr[x][y];
        vector<pair<int,int>> move = {{2,1} , {1 , 2} , {-1 , 2} , {-2 , 1} , {-2 , -1} , {-1 , -2} , {1 , -2} , {2 , -1}};
        while(!q.empty()){
            int size= q.size();
            int coins_var =0;
            while(size--){
                auto it= q.front();
                q.pop();
                int nx = it.first;
                int ny = it.second;
                coins_var += arr[nx][ny];
                for(auto i: move){
                    int new_x = i.first + nx;
                    int new_y = i.second + ny;
                    if(new_x >=0 && new_x<n && new_y>=0 && new_y<m && !vis[new_x][new_y]){
                        vis[new_x][new_y] =1;
                        // coins_var+= arr[new_x][new_y];
                        q.push({new_x , new_y});
                    }
                }
            }
            coins.push_back(coins_var);
        }
        int coins_size = coins.size();
        int ans = 0;
        for(int i= coins_size-1 ; i>=0;i--){
            if(i+ coins[i] < coins_size){
                coins[i] += coins[i + coins[i]];
            }
        }
        int max_val =0;
        for(int i= 0; i<coins_size ; i++){
            if( coins[i] > max_val ){
                max_val = coins[i];
                ans = i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends