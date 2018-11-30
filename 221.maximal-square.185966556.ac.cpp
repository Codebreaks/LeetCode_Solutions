/*
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (31.39%)
 * Total Accepted:    105.9K
 * Total Submissions: 337.4K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
        
        int maxsqlen = 0;
        
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                if (matrix[i][j] == '1') 
                {
                    
                    int sqlen = 1;
                    bool flag = true;
                    while (sqlen + i < rows && sqlen + j < cols && flag) 
                    {
                        for (int k = j; k <= sqlen + j; k++) {
                            if (matrix[i + sqlen][k] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        for (int k = i; k <= sqlen + i; k++) {
                            if (matrix[k][j + sqlen] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                            sqlen++;
                    }
                    if (maxsqlen < sqlen) 
                    {
                        maxsqlen = sqlen;
                    }
                }
            }
        }
        
        return maxsqlen * maxsqlen;
        
    }
};
