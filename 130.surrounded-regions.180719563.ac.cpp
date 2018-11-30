/*
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (20.86%)
 * Total Accepted:    117K
 * Total Submissions: 561.1K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */
class Solution {
public:
bool solve2(vector<vector<char>>& board, int currow, int curcol, int maxRow, int maxCol)
{

    if (currow == 0 || currow == maxRow - 1 || curcol == 0 || curcol == maxCol - 1) return false;

	board[currow][curcol] = '+';
	
	bool ret = true;

    
        // left
	if ((curcol - 1) >= 0 && board[currow][curcol - 1] == 'O')
		ret = solve2(board, currow, curcol - 1, maxRow, maxCol);

	// right
	if (ret && ((curcol + 1) < maxCol) && board[currow][curcol + 1] == 'O')
		ret = solve2(board, currow, curcol + 1, maxRow, maxCol);
    
    //Up
	if (ret && ((currow - 1) >= 0) && board[currow - 1][curcol] == 'O')
		ret = solve2(board, currow - 1, curcol, maxRow, maxCol);

	//Down
	if (ret && ((currow + 1) < maxRow) && board[currow + 1][curcol] == 'O')
		ret = solve2(board, currow + 1, curcol, maxRow, maxCol);
    
    if(currow == processi && curcol == processj)
    {
	    if(ret == false)
        {
                for (int i = 0; i < maxRow; i++)
                {
                    for (int j = 0; j < maxCol; j++)
                    {
                        if(board[i][j] == '+') board[i][j] = 'O';

                    }

                }

        }
            else
            {
                 for (int i = 0; i < maxRow; i++)
                {
                    for (int j = 0; j < maxCol; j++)
                    {
                        if(board[i][j] == '+') board[i][j] = 'X';

                    }

                }
            }
    }
    
	return ret;
}
    int processi, processj;

void solve(vector<vector<char>>& board)
{
	int rows = board.size();
	if (!rows) return;
	int cols = board[0].size();

	map<pair<int, int>, bool> lastResult;
	

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (board[i][j] == 'O')
			{
				bool last = true;
                
                processi = i;
                processj = j;
                
                solve2(board, i, j, rows, cols);
              
			}
		}
	}
}
    
};
