//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:


bool helper( int i , int j , int n , int m ,  auto &board  , auto &word , int index){
    if(index>= word.size()) return true;

    if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='.' || word[index]!=board[i][j]) return false;
    if(word.size()==1 && word[index]==board[i][j]) return true;
    
    board[i][j]='.';
    bool temp = false;
    vector<pair<int,int>> move = { {0,-1} ,{0,1} , {1,0} ,{-1,0}};
    
    for(auto it : move){
        int row = it.first + i;
        int col = it.second + j;
        
        temp = temp || helper(row  , col , n, m ,board , word , index+1);
    }
    board[i][j]=word[index];
    return temp;
}

    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        if(word=="") return true;
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0 ; i<n ;i++){
            for(int j=0 ; j<m ;j++){
                if( board [ i] [j ] == word[0]){
                    if(helper(i , j , n, m ,board ,word ,0)) return true;
                }
            }
        }
        return false;
    }
    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends