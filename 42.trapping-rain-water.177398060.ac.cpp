/*
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (39.35%)
 * Total Accepted:    203.6K
 * Total Submissions: 517.5K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 */
class Solution {
public:
int trap(vector<int>& height) 
{
	if (!height.size()) return 0;
    int left = 0;
	int right = height.size() - 1;
	int maxleft = height[left];
	int maxright = height[right];
	int maxWater = 0;

	while(left < right)
	{
		maxleft = max(maxleft, height[left]);
		maxright = max(maxright, height[right]);

		if (maxleft < maxright)
		{
			maxWater += (maxleft - height[left]);
			left++;
		}
		else
		{
			maxWater += (maxright - height[right]);
			right--;
		}
	}
	return maxWater;
}
};
