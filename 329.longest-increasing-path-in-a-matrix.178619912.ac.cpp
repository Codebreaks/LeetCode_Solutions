/*
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (37.88%)
 * Total Accepted:    63.4K
 * Total Submissions: 167.4K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 * 
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = 
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ] 
 * Output: 4 
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = 
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ] 
 * Output: 4 
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 * 
 * 
 */
class Solution {
public:
    
    int maxRows;
    int maxCols;
    
int longestIncreasingPath2(vector<vector<int>>& matrix, vector<vector<int>>& dp, int currow, int curcol)
{

	int score = 1;
    

	if (dp[currow][curcol] != -1) return dp[currow][curcol];
    
    // cout << "currow "<< currow << " curcol "<< curcol << endl;

	//left
	if (((curcol - 1) >= 0) && (matrix[currow][curcol] < matrix[currow][curcol - 1]))
    {
        score = max(score, (1 + longestIncreasingPath2(matrix, dp, currow, curcol - 1)));
        // cout << "left " << score << endl;
    }
		

	// right
    cout << (matrix[currow][(curcol + 1)] > matrix[currow][curcol]) << endl;
    cout << ((curcol + 1) < maxCols) << endl;
    
	if (((curcol + 1) < maxCols) && (matrix[currow][(curcol + 1)] > matrix[currow][curcol]))
    {
                // cout << "right " << score << endl;

        score = max(score, (1 + longestIncreasingPath2(matrix, dp, currow, curcol + 1)));
    }
		


	//Up
	if (((currow - 1) >= 0) && (matrix[currow - 1][curcol] > matrix[currow][curcol]))
    {
        score = max(score, (1 + longestIncreasingPath2(matrix, dp, currow - 1, curcol)));
        // cout << "Up " << score << endl;
    }
		

	//Down
	if (((currow + 1) < maxRows) && (matrix[currow + 1][curcol] > matrix[currow][curcol]))
    {
        score = max(score, (1 + longestIncreasingPath2(matrix, dp, currow + 1, curcol)));
        // cout << "Down " << score << endl;
    }
		

	dp[currow][curcol] = score;
    
	return dp[currow][curcol];

}


int longestIncreasingPath(vector<vector<int>>& matrix) {

	int ans = INT_MIN;
    
    if(!matrix.size()) return 0;
    
   maxRows = matrix.size();
    maxCols = matrix[0].size();
    
    // cout << "Rows "<< maxRows << endl;
    // cout << "Cols "<< maxCols << endl;
    

    
	vector<int> p(maxCols, -1);
    
	vector<vector<int>> dp(maxRows, p);

	
	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxCols; j++)
		{
			if(dp[i][j] == -1)
                longestIncreasingPath2(matrix, dp, i, j);
            
			ans = max(ans, dp[i][j]);
            
            // cout << ans << endl;
		}
	}
	return ans;
}
    
};
