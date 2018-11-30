/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (29.02%)
 * Total Accepted:    210.1K
 * Total Submissions: 723.9K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Solution {
public:
bool exists2(vector<vector<char>>& board, string word, int currow, int curcol, int maxRow, int maxCol, int curIndex)
{
	char curChar = board[currow][curcol];
	if (curChar != word[curIndex]) return false;
	if (curIndex == (word.size() - 1)) return true;
	
	board[currow][curcol] = '*';

	bool ret = false;

	//left
	if ((curcol - 1) >= 0)
		ret = exists2(board, word, currow, curcol - 1, maxRow, maxCol, curIndex + 1);

	// right
	if ( !ret && ((curcol + 1) < maxCol))
		ret = exists2(board, word, currow, curcol + 1, maxRow, maxCol, curIndex + 1);

	//Up
	if ( !ret && ((currow - 1) >= 0))
		ret = exists2(board, word, currow-1, curcol, maxRow, maxCol, curIndex + 1);

	//Down
	if (!ret &&  ((currow + 1) < maxRow)  )
		ret = exists2(board, word, currow + 1, curcol, maxRow, maxCol, curIndex + 1);
	
	board[currow][curcol] = curChar;
	return ret;
}


bool exist(vector<vector<char>>& board, string word) {

	int rows = board.size();
	if (!rows) return false;
	int cols = board[0].size();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (exists2(board, word, i, j, rows, cols, 0)) return true;
		}
	}
	return false;
}
};
