//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool safe(int row , int col , vector<vector<int>> board , int n){
        
        /*
        \  |  /
         \ | /
          \|/
          */
        int drow = row;
        int dcol = col;
        
        //for ex , ab 2nd col mai queen place krne aay , toh fir second col mai...uske aage ke row mai , uske aage ke diagnol
        // pe check krne ki jrurat nhi kuki abii to waha kuchh place hii nhi kiaa
        
        //uoar ki col mai minus krke check krr rheee
        while(dcol>=0){
            if(board[drow][dcol]==1) return false;
            dcol--;
        }
        dcol =col;
        
        //diagnol check
        while(drow>=0 && dcol>=0){
            if(board[drow][dcol]==1) return false;
            dcol--;
            drow--;
        }
        drow = row;
        dcol = col;
        
        //dusri diagnol check
        while(drow<n && dcol>=0){
            if(board[drow][dcol]==1) return false;
            drow++;
            dcol--;
        }
        return true;
    }
    
    void solve(int col , int n , vector<vector<int>> board ,vector<vector<int>> &ans){
        //base case, hum col mai aage hii tab bdte hai jab ek queen place hojay
        if(col==n){
            vector<int>temp;
            //colum wise traverse krke ek 2d matrix mai, to jaha pe bhi queen rkhi hogi wo le lenge colum wise
            for(int col=0; col<n; col++){
                for(int row = 0 ; row<n; row++){
                    if(board[row][col]==1){
                        temp.push_back(row +1);
                    }
                }
            }
            
            ans.push_back(temp);
            return;
        }
        
        //base case ends here
        for(int row = 0 ; row < n; row++){
            if(safe(row , col ,board , n)){
                board[row][col]=1;
                solve(col +1 , n , board ,ans);
                board[row][col]=0;   //backtrack
            }
        }
        
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<vector<int>> board(n , vector<int> (n,0));
        
        solve(0 , n , board , ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
