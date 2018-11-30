/*
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (38.09%)
 * Total Accepted:    226.3K
 * Total Submissions: 594.2K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 * 
 */
class Solution {
public:
void MarkNeighbors(vector<vector<char>>& grid, int currow, int curcol)
{
	int row = grid.size();
	int col = grid[0].size();
	grid[currow][curcol] = '0';

	//left
	if (((curcol - 1) >= 0) && (grid[currow][(curcol - 1)] == '1'))
		MarkNeighbors(grid, currow, curcol - 1);

	// right
	if (((curcol + 1) < col) && (grid[currow][(curcol + 1)] == '1'))
		MarkNeighbors(grid, currow, curcol + 1);

	//Up
	if (((currow - 1) >= 0) && (grid[currow - 1][curcol] == '1'))
		MarkNeighbors(grid, currow - 1, curcol);

	//Down
	if (((currow + 1) < row) && (grid[currow + 1][curcol] == '1'))
		MarkNeighbors(grid, currow + 1, curcol);

}

int numIslandsNoVisited(vector<vector<char>>& grid) 
{
	int row = grid.size();
    if (!row) return 0;
	int col = grid[0].size();

	vector<vector<bool>> visited(row, vector<bool>(col, false));
	int iland = 0;

	for (int currow = 0; currow < row; currow++)
	{
		for (int curcol = 0; curcol < col; curcol++)
		{
			if (grid[currow][curcol] == '1')
			{
				iland++;
				MarkNeighbors(grid, currow, curcol);
			}
		}
	}
	return iland;
}
    
void MarkNeighborsVisited(vector<vector<char>>& grid, int currow, int curcol, vector<vector<bool>>& visited)
{
	int row = grid.size();
	int col = grid[0].size();
	visited[currow][curcol] = true;

	//left
	if (((curcol - 1) >= 0) && (grid[currow][(curcol - 1)] == '1') && visited[currow][(curcol - 1)] == false)
		MarkNeighborsVisited(grid, currow, curcol - 1, visited);

	// right
	if (((curcol + 1) < col) && (grid[currow][(curcol + 1)] == '1') && visited[currow][(curcol + 1)] == false)
		MarkNeighborsVisited(grid, currow, curcol + 1, visited);

	//Up
	if (((currow - 1) >= 0) && (grid[currow - 1][curcol] == '1') && visited[currow - 1][curcol] == false)
		MarkNeighborsVisited(grid, currow - 1, curcol, visited);

	//Down
	if (((currow + 1) < row) && (grid[currow + 1][curcol] == '1') && visited[currow + 1][curcol] == false)
		MarkNeighborsVisited(grid, currow + 1, curcol, visited);

}

int numIslands(vector<vector<char>>& grid) 
{
	int row = grid.size();
    if (!row) return 0;
	int col = grid[0].size();
    
    vector<bool> eachrow(grid[0].size(), false);
    
    // vector<vector<bool>> visited(grid.size(), eachrow);

	vector<vector<bool>> visited(row, vector<bool>(col, false));
    
	int iland = 0;

	for (int currow = 0; currow < row; currow++)
	{
		for (int curcol = 0; curcol < col; curcol++)
		{
			if (grid[currow][curcol] == '1' && visited[currow][curcol] == false)
			{
				iland++;
				MarkNeighborsVisited(grid, currow, curcol, visited);
			}
		}
	}
	return iland;
}
    
    
};
