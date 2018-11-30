/*
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Easy (53.17%)
 * Total Accepted:    47.8K
 * Total Submissions: 89.9K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.)  You
 * may assume all four edges of the grid are surrounded by water.
 * 
 * Find the maximum area of an island in the given 2D array.
 * (If there is no island, the maximum area is 0.)
 * 
 * Example 1:
 * 
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * 
 * Given the above grid, return 6.
 * 
 * Note the answer is not 11, because the island must be connected
 * 4-directionally.
 * 
 * 
 * Example 2:
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 * 
 * 
 * Note:
 * The length of each dimension in the given grid does not exceed 50.
 * 
 */
class Solution {
public:
void MarkNeighbors2(vector<vector<int>>& grid, int currow, int curcol, int& curArea)
{
	int row = grid.size();
	int col = grid[0].size();
	
	curArea++;
	grid[currow][curcol] = 0;

	//left
	if (((curcol - 1) >= 0) && (grid[currow][(curcol - 1)] == 1))
		MarkNeighbors2(grid, currow, curcol - 1, curArea);

	// right
	if (((curcol + 1) < col) && (grid[currow][(curcol + 1)] == 1))
		MarkNeighbors2(grid, currow, curcol + 1, curArea);

	//Up
	if (((currow - 1) >= 0) && (grid[currow - 1][curcol] == 1))
		MarkNeighbors2(grid, currow - 1, curcol, curArea);

	//Down
	if (((currow + 1) < row) && (grid[currow + 1][curcol] == 1))
		MarkNeighbors2(grid, currow + 1, curcol, curArea);

}

//int numIslands(vector<vector<char>>& grid)
int maxAreaOfIsland(vector<vector<int>>& grid) 
{
	int row = grid.size();
	if (!row) return 0;
	int col = grid[0].size();

	int iland = 0;
	int maxArea = 0;

	for (int currow = 0; currow < row; currow++)
	{
		for (int curcol = 0; curcol < col; curcol++)
		{
			if (grid[currow][curcol] == 1)
			{
				int curArea = 0;
				
				MarkNeighbors2(grid, currow, curcol, curArea);

				maxArea = maxArea < curArea ? curArea : maxArea;
			}
		}
	}
	return maxArea;
}
};
