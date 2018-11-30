/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (41.31%)
 * Total Accepted:    375.5K
 * Total Submissions: 909K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
public:
int maxSubArray(vector<int>& nums) {
	int max = 0;
	int curMax = 0;
    
	if (!nums.size()) return 0;
    
   	for (int i = 0; i < nums.size(); i++)
	{
		curMax += nums[i];
		if (curMax < 0) curMax = 0;
		else
			max = max > curMax ? max : curMax;
	}
    	if (!max)
	{
		sort(nums.begin(), nums.end());
		max = nums.back();
	}
	return max;
}
};
