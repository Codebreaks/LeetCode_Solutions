/*
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (28.81%)
 * Total Accepted:    136.5K
 * Total Submissions: 473.8K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        
        int maxsize = INT_MIN;
		for (int i = 0; i < (height.size() - 1); i++)
		{

			for (int j = (i + 1); j < height.size(); j++)
			{
				
				(min(height[i], height[j]) * (j - i)) > maxsize ? maxsize = (min(height[i], height[j]) * (j - i)) : maxsize = maxsize;
			}
		}
		return maxsize;
    }
};
