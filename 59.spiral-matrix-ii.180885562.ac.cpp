/*
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (43.65%)
 * Total Accepted:    116.7K
 * Total Submissions: 267.3K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int z) 
    {
     
     
	 int m = z, n = z;
     
    int start = 0;
        
     vector<int> rz(n,0);
	 vector<vector<int>> matrix(m,rz);

	 int l, r, d, u, k;
	 l = u = k = 0;
	 d = m - 1;
	 r = n - 1;

	 while (true)
	 {
		 for (int col = l; col <= r; col++)
			 matrix[u][col] = ++start;
		 if (++u > d) break;

		 for (int row = u; row <= d; row++)
			 matrix[row][r] = ++start;
		 if (--r < l) break;

		 for (int col = r; col >= l; col--)
			 matrix[d][col] = ++start;
         
		 if (--d < u) break;

		 for (int row = d; row >= u; row--)
			 matrix[row][l] = ++start;
		 if (++l > r) break;
	 }
     
     return matrix;
    }
};
