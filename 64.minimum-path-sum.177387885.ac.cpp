/*
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (43.10%)
 * Total Accepted:    176.9K
 * Total Submissions: 410.5K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */
class Solution {
public:
// int minSum = INT_MAX;

// void minPathSum2(vector<vector<int>>& grid, int row, int col, int maxRow, int MaxCol, int sum)
// {
// 	if (row == maxRow || col == MaxCol) return;
	
// 	sum += grid[row][col];

// 	if (row == maxRow - 1 && col == MaxCol - 1)
// 	{ 
// 		minSum = min(minSum, sum);
// 		return;
// 	}

// 	minPathSum2(grid, row, col + 1, maxRow, MaxCol, sum);
// 	minPathSum2(grid, row+1, col, maxRow, MaxCol, sum);
// }

// int minPathSum(vector<vector<int>>& grid) 
// {
// 	minPathSum2(grid, 0, 0, grid.size(), grid[0].size(), 0);
// 	return minSum;
// }
    
    // taken code coz my solution is TLE
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 
        vector<vector<int> > sum(m, vector<int>(n, grid[0][0]));
        for (int i = 1; i < m; i++)
            sum[i][0] = sum[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++)
            sum[0][j] = sum[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                sum[i][j]  = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
        return sum[m - 1][n - 1];
    }
};
