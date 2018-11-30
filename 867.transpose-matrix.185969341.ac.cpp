/*
 * [898] Transpose Matrix
 *
 * https://leetcode.com/problems/transpose-matrix/description/
 *
 * algorithms
 * Easy (64.23%)
 * Total Accepted:    21.4K
 * Total Submissions: 33.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix A, return the transpose of A.
 * 
 * The transpose of a matrix is the matrix flipped over it's main diagonal,
 * switching the row and column indices of the matrix.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[1,4,7],[2,5,8],[3,6,9]]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,2,3],[4,5,6]]
 * Output: [[1,4],[2,5],[3,6]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 1000
 * 1 <= A[0].length <= 1000
 * 
 * 
 * 
 */
class Solution {
public:
    
//Seuare matrix no extra memory
vector<vector<int>> transpose1(vector<vector<int>>& A) 
{
	int count = 0;
	int rows = A.size();
    int cols = A[0].size();
    
	for (int i = 0; i < rows; i++)
	{
		for (int j = count; j < cols; j++)
		{
			int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
		}
		count++;
	}
	return A;
}
    
// work sfor all kinds of matrix but uses extra memory
vector<vector<int>> transpose(vector<vector<int>>& A)
{
	int count = 0;
	int rows = A.size();
	int cols = A[0].size();

	vector<vector<int>> matrix;

	for (int i = 0; i < cols; i++)
	{
		vector<int> temp;
		for (int j = 0; j < rows; j++)
		{
			temp.push_back(A[j][i]);
		}
		matrix.push_back(temp);
		temp.clear();
	}
	return matrix;
}
    
};
