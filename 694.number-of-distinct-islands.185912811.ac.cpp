/*
 * [694] Number of Distinct Islands
 *
 * https://leetcode.com/problems/number-of-distinct-islands/description/
 *
 * algorithms
 * Medium (47.38%)
 * Total Accepted:    14.7K
 * Total Submissions: 31.1K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.)  You
 * may assume all four edges of the grid are surrounded by water.
 * 
 * Count the number of distinct islands.  An island is considered to be the
 * same as another if and only if one island can be translated (and not rotated
 * or reflected) to equal the other.
 * 
 * Example 1:
 * 
 * 11000
 * 11000
 * 00011
 * 00011
 * 
 * Given the above grid map, return 1.
 * 
 * 
 * Example 2:
 * 11011
 * 10000
 * 00001
 * 11011
 * Given the above grid map, return 3.
 * Notice that:
 * 
 * 11
 * 1
 * 
 * and
 * 
 * ⁠1
 * 11
 * 
 * are considered different island shapes, because we do not consider
 * reflection / rotation.
 * 
 * 
 * Note:
 * The length of each dimension in the given grid does not exceed 50.
 * 
 */
class Solution {
public:
void DistinctDFS(vector<vector<int>>& grid, int row, int col, int maxRow, int maxCol, string& curPath, char dir)
{
	if (row < maxRow && row > -1 && col > -1 && col < maxCol && grid[row][col] == 1)
	{
		curPath += dir;

		grid[row][col] = 0;

		DistinctDFS(grid, row-1, col, maxRow, maxCol, curPath, 'u');
		curPath += 'b';
		DistinctDFS(grid, row+1, col, maxRow, maxCol, curPath, 'd');
		curPath += 'b';
		DistinctDFS(grid, row, col-1, maxRow, maxCol, curPath, 'l');
		curPath += 'b';
		DistinctDFS(grid, row, col+1, maxRow, maxCol, curPath, 'r');
		curPath += 'b';
	}
}

int numDistinctIslands(vector<vector<int>>& grid) 
{
	unordered_set<string> paths;
	int maxRow = grid.size();
	int maxCol = grid[0].size();

	for (int i = 0; i < maxRow; i++)
	{
		for (int j = 0; j < maxCol; j++)
		{
			if (grid[i][j] == 1)
			{
				string curPath;
				DistinctDFS(grid, i, j, maxRow, maxCol, curPath, 's');
				paths.insert(curPath);
			}
		}
	}
	return paths.size();
}
};
