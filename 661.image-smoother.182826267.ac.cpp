/*
 * [661] Image Smoother
 *
 * https://leetcode.com/problems/image-smoother/description/
 *
 * algorithms
 * Easy (47.09%)
 * Total Accepted:    26.1K
 * Total Submissions: 55.4K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a 2D integer matrix M representing the gray scale of an image, you
 * need to design a smoother to make the gray scale of each cell becomes the
 * average gray scale (rounding down) of all the 8 surrounding cells and
 * itself.  If a cell has less than 8 surrounding cells, then use as many as
 * you can.
 * 
 * Example 1:
 * 
 * Input:
 * [[1,1,1],
 * ⁠[1,0,1],
 * ⁠[1,1,1]]
 * Output:
 * [[0, 0, 0],
 * ⁠[0, 0, 0],
 * ⁠[0, 0, 0]]
 * Explanation:
 * For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
 * For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
 * For the point (1,1): floor(8/9) = floor(0.88888889) = 0
 * 
 * 
 * 
 * Note:
 * 
 * The value in the given matrix is in the range of [0, 255].
 * The length and width of the given matrix are in the range of [1, 150].
 * 
 * 
 */
class Solution {
public:
int getValue(vector<vector<int>>& M, int i, int j)
{
	float count = 0.0f;
	float sum = 0.0f;
	int rowMax = M.size();
	int colMax = M[0].size();

	count++;
	sum += M[i][j];
    
    

	if (j-1 >=0) 
	{
		if (i - 1 >= 0)
		{
			count++;
			sum += M[i-1][j - 1];
		}
		if (i + 1 < rowMax)
		{
			count++;
			sum += M[i + 1][j - 1];
		}
		count++;
		sum += M[i][j - 1];
	}

	if (j + 1 < colMax)
	{
		
        if (i - 1 >= 0)
		{
			count++;
			sum += M[i - 1][j + 1];
		}
        
       
		if (i + 1 < rowMax)
		{
            count++;
			sum += M[i + 1][j + 1];
		}
        
		count++;
		sum += M[i][j + 1];
	}

	if (i - 1 >= 0)
	{
		count++;
		sum += M[i - 1][j];
	}
	if (i + 1 < rowMax)
	{
		count++;
		sum += M[i + 1][j];
	}

	return floor(sum / count);
}

vector<vector<int>> imageSmoother(vector<vector<int>>& M) 
{
	vector<int> k(M[0].size(), 0);
	vector<vector<int>> ans(M.size(), k);
    
	for (int i = 0; i < M.size(); i++)
	{
		for (int j = 0; j < M[0].size(); j++)
		{
			ans[i][j] = getValue(M, i, j);
		}
	}
	return ans;
}
};
