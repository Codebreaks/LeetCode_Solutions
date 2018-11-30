/*
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (34.43%)
 * Total Accepted:    180.2K
 * Total Submissions: 523.5K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        
        int row = matrix.size();
        if(!row) return false;
        
        int col = matrix[0].size();

        int curCol = col - 1;
        int curRow = 0;

        while (curCol >=0 && curRow < row)
        {
            // cout << matrix[curRow][curCol] << "\n";
            if (matrix[curRow][curCol] == target) return true;
            else if (matrix[curRow][curCol] < target) curRow++;
            else curCol--;
        }
        return false;
    }
};
