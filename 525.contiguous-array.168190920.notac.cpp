/*
 * [525] Contiguous Array
 *
 * https://leetcode.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (41.98%)
 * Total Accepted:    31.3K
 * Total Submissions: 74.5K
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array, find the maximum length of a contiguous subarray with
 * equal number of 0 and 1. 
 * 
 * 
 * Example 1:
 * 
 * Input: [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with equal number of
 * 0 and 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 * 
 * 
 * 
 * Note:
 * The length of the given binary array will not exceed 50,000.
 * 
 */
class Solution {
public:
int findMaxLength(vector<int>& nums) {
	int max = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		int o = 0;
		int z = 0;
		for (int j = i; j < nums.size(); j++)
		{
			nums[j] == 0? ++z: ++o;
			if (o == z && ((o + z) > max)) max = (o + z);
		}

	}
	return max;
}
};
