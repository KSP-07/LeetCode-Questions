class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int lowerBound_i = 0 , lowerBound_j = 0;
        int col = n , row = n ;
        int total = n*n;
        int num = 1;
        vector<vector<int>> ans(n, vector<int>(n));
        while(num<= total ){
            int i = lowerBound_i , j = lowerBound_j ;
            
            while(j<col){
                ans[i][j] = num;
                j++;
                num++;
            }
            lowerBound_i+=1;
            j= col-1;
            i = lowerBound_i;
            while(i<row){
                ans[i][j] = num;
                num++;
                i++;
            }
            col-=1;
            i = row-1;
            j = col-1;
            
            while(j>=lowerBound_j){
                ans[i][j] = num;
                j--;
                num++;
            }
            row -=1;
            j= lowerBound_j;
            i=row-1;
            while(i>=lowerBound_i){
                ans[i][j] = num;
                i--;
                num++;
            }
            lowerBound_j+=1;
        }
        return ans;
    }
};