/*
 * [733] Flood Fill
 *
 * https://leetcode.com/problems/flood-fill/description/
 *
 * algorithms
 * Easy (48.06%)
 * Total Accepted:    24.9K
 * Total Submissions: 51.8K
 * Testcase Example:  '[[1,1,1],[1,1,0],[1,0,1]]\n1\n1\n2'
 *
 * 
 * An image is represented by a 2-D array of integers, each integer
 * representing the pixel value of the image (from 0 to 65535).
 * 
 * Given a coordinate (sr, sc) representing the starting pixel (row and column)
 * of the flood fill, and a pixel value newColor, "flood fill" the image.
 * 
 * To perform a "flood fill", consider the starting pixel, plus any pixels
 * connected 4-directionally to the starting pixel of the same color as the
 * starting pixel, plus any pixels connected 4-directionally to those pixels
 * (also with the same color as the starting pixel), and so on.  Replace the
 * color of all of the aforementioned pixels with the newColor.
 * 
 * At the end, return the modified image.
 * 
 * Example 1:
 * 
 * Input: 
 * image = [[1,1,1],[1,1,0],[1,0,1]]
 * sr = 1, sc = 1, newColor = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation: 
 * From the center of the image (with position (sr, sc) = (1, 1)), all pixels
 * connected 
 * by a path of the same color as the starting pixel are colored with the new
 * color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally
 * connected
 * to the starting pixel.
 * 
 * 
 * 
 * Note:
 * The length of image and image[0] will be in the range [1, 50].
 * The given starting pixel will satisfy 0  and 0 .
 * The value of each color in image[i][j] and newColor will be an integer in
 * [0, 65535].
 * 
 */
class Solution {
public:
    
    typedef struct point 
{
	int r;
	int c;
} pnt;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
{
	queue<pnt> myqueue;

	if (!image.size()) return image;

	pnt input;
	input.r = sr;
	input.c = sc;

	int sourcecolor = image[sr][sc];
	myqueue.push(input);
	while (!myqueue.empty())
	{

		pnt pt = myqueue.front();
		myqueue.pop();

		int row = pt.r;
		int col = pt.c;

		image[row][col] = -1;

		if (col + 1 <image[0].size()) // right
		{
			if (image[row][col + 1] == sourcecolor)
			{

				pnt rt;
				rt.r = row;
				rt.c = col + 1;

				myqueue.push(rt);
			}
		}
		if (col - 1 >= 0) // left
		{
			if (image[row][col - 1] == sourcecolor)
			{

				pnt rt;
				rt.r = row;
				rt.c = col - 1;
				myqueue.push(rt);
			}
		}
		if (row + 1 < image.size()) //down
		{
			if (image[row + 1][col] == sourcecolor)
			{

				pnt rt;
				rt.r = row + 1;
				rt.c = col;
				myqueue.push(rt);
			}
		}
		if (row - 1 >= 0) //up
		{
			if (image[row - 1][col] == sourcecolor)
			{

				pnt rt;
				rt.r = row - 1;
				rt.c = col;
				myqueue.push(rt);
			}
		}
	}

	for (int i = 0; i < image.size(); i++)
	{
		for (int j = 0; j < image[0].size(); j++)
		{
			if (image[i][j] == -1) image[i][j] = newColor;
		}
	}

	return image;

}
    

    
};
