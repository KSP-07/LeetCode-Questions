
/*class Solution {
public:
    int m, n;
    int solve(vector<vector<int>>&grid, int currRow, int currCol)
    {
        if (currRow >= m || currCol >= n) return INT_MAX; //when cell is out of bounds
        if (currRow == m - 1 && currCol == n - 1) return grid[m - 1][n - 1]; //reached the target
        
        int rightMin = solve(grid, currRow, currCol + 1);
        int downMin = solve(grid, currRow + 1, currCol);
        int bestChoice = min(rightMin, downMin);
        
        return (grid[currRow][currCol] + bestChoice);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        m = grid.size(); n = grid[0].size();
        return solve(grid, 0, 0);
    }
};
*/
class Solution {
public:
    int m, n;
    int solve(vector<vector<int>>&grid, vector<vector<int>>&dp, int currRow, int currCol)
    {
        //only these 2 out of bound conditions will arrive as we are making call to 'right' and 'down' cell only
        if (currRow >= m || currCol >= n) return INT_MAX; //when cell is out of bounds
        if (currRow == m - 1 && currCol == n - 1) return grid[m - 1][n - 1]; //reached the target
        
        if (dp[currRow][currCol] !=  -1) return dp[currRow][currCol]; //use the already computed result
        int rightMin = solve(grid, dp, currRow, currCol + 1);
        int downMin = solve(grid, dp, currRow + 1, currCol);
        int bestChoice = min(rightMin, downMin);
        
        return dp[currRow][currCol] = (grid[currRow][currCol] + bestChoice); //store the result 
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        m = grid.size(); n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1)); 
        //'-1' to denote that subproblem result for that cell is not computed and not stored
        return solve(grid, dp, 0, 0);
    }
};

/*
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        //traverse from 'bottom->top' and 'right->left'
        //as for any cell we need computed result from 'down' and 'right'
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1) continue;
                
                //grid[i][j + 1] and grid[i + 1][j] will already have stored the result of subproblem
                int rightMin = (j + 1 >= n)? INT_MAX : grid[i][j + 1]; //
                int downMin = (i + 1 >= m)? INT_MAX : grid[i + 1][j];
                grid[i][j] = grid[i][j] + (min(rightMin, downMin)); 
                //rather than making a new 'DP' grid store results of subproblems in the same grid
            }
        }
        return grid[0][0];
        
    }
};
*/