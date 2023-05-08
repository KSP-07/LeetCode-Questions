class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0 ; 
        for( int i=0 , j = n-1  , k = 0; i<n && j>=0 ; i++ , j-- , k++){
            sum += mat[i][i];
            
            if(i==j) continue;
            
            sum += mat[j][k];
        }
        return sum;
    }
};