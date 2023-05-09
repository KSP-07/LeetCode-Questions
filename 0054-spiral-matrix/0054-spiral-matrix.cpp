class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int l_i = 0 , l_j =0 ;
        int total =  n * m ;
        
        while(total){
            int i = l_i , j = l_j ;
            
            
            //1 2 3 4
            while(j<m && total){
                ans.push_back(matrix[i][j]);
                j++;
                total--;
            }
            j =m-1;
            l_i++;
            i=l_i; // i = 1;
            
            // 8 12
            while(i< n && total){
                ans.push_back(matrix[i][j]);
                i++;
                total--;
            }
            i =n-1;
            m-=1;  //m=3
            j = m-1;             // j 2
            
            //
            while(j>=l_j && total){
                ans.push_back(matrix[i][j]);
                j--;
                total--;                
            }
            j= l_j;
            n-=1;
            i = n-1;         
            while(i>=l_i && total){
                ans.push_back(matrix[i][j]);
                i--;
                total--;
            }   
            l_j++;
        }
        return ans;
    }
};