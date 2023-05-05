//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    
    bool isSafe(int node , bool graph[101][101] , vector<int> &color , int n , int color_val){
        for(int k=0; k<n ;k++){
            //k is checking that it's not equal to the node we colored and k is traversing for adjacent nodes
            //is any other node than the parent has same color val , it means the prev color is used and since
            // these node are adjacent, they can not have the same color, so false
            
            //basically, 2nd condition checks that if there is edge in adj matrix
            //if 2nd is true then third checks that the other node has same colour
            if(k!= node && graph[k][node]==1 && color[k]==color_val ) return false;  // [k][node] is like if node is 0 , then 1 0 , 2 0 ,3 0...adjacent
        }
        return true;
    }

    bool solve(bool graph[101][101] , vector<int>&color ,int node, int n ,int m){
        //base case
        if(node==n){
            return true;  //graph has reached to n by coloring all the nodes
        }
        
        //traversing for checking that we can put each color or not , 'recursion'
        //basically, hrr vertex pe suruvat se colour daalne ka try krenge
        for(int i=1;i<=m;i++){
            //checking if we can use the current color or not
            if(isSafe(node , graph , color , n , i)){
                //using the current color
                color[node]=i;
                //if recursion return true , then it means we do not have to check for any more cases, so we return true
                if(solve( graph , color , node + 1 , n , m)) return true;
                
                //if our ans on prev recursion was false , to try others , we make the color as same before('backtracking')
                color[node]=0 ;
            }
        }
        
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> col(n , 0);   //using N size coz we will use to access node's color
        // for(int i=1;i<=m;i++) col[i-1]=i;
        return solve(graph , col ,0, n,m);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
