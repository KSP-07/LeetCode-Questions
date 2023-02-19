//REFERENCE VIDEO - https://www.youtube.com/watch?v=zWS2fCJGxmU
class Solution {
public:
    
     //Function returns a vector of integers, representing the coordinates (row and column) of the element at position curr on the board.
    vector<int> findCoordinates( int currVal , int n){
                //calculates the row by subtracting the quotient of (curr-1) / n from n-1. This is done to convert the 1-indexed position of the element to a 0-indexed position in the board.

        //since , board is starting from n-1
        int row = n - (currVal - 1) / n - 1;
        //col is jig jagged , so need to further check it
        int col = (currVal -1)%n;
        
        //
        if(row%2 == n%2){
            return {row , n - 1 -col};
        }
        else return {row , col};
    }
    
    
    //using bfs to count min distance as it counts step by step , so all possible step from ith pos to new 
    //pos will counted as 1 step only
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        int moves =0;
        queue<int> q;
        
        vector<vector<bool>> visited(n , vector<bool>(n,false));
        
        q.push(1);
        visited[n-1][0]=true;
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0 ; i<size; i++){
                int currBoardVal = q.front();
                q.pop();
                
                if(currBoardVal == n*n) return moves;
                
                //traversing on each possible dice roll
                for(int dice = 1 ; dice <= 6 ; dice++){
                    //if the new pos exceeds the board
                    if(currBoardVal + dice > n*n ) break;
                    
                    //it is used to find the next pos possible in matrix
                    vector<int> pos = findCoordinates( currBoardVal + dice , n);
                    
                    int row = pos[0];
                    int col = pos[1];
                    
                    if(!visited[row][col]){
                        visited[row][col]=1;
                        
                        if(board[row][col] == -1){
                            //is no snake or ladder , normal new possible reachable value
                            q.push(currBoardVal + dice);
                        }
                        else{
                            //in case of snake and ladder , new value according to the matrix
                            q.push(board[row][col]);
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};