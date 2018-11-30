/*
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (39.38%)
 * Total Accepted:    133.6K
 * Total Submissions: 339.2K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * Example:
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 * 
 */
class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
	int row = matrix.size();
    if(row==0 ) return false;
    
	int col = matrix[0].size();
    if(col ==0) return false;

	int curCol = col - 1;
	int curRow = 0;

	while (curCol >=0 && curRow < row)
	{
		
        if (matrix[curRow][curCol] == target) return true;
        
		else if (target > matrix[curRow][curCol] ) curRow++;
		
        else curCol--;
	}
	return false;
}
};
