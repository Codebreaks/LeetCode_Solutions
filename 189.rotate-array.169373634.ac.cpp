/*
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (27.04%)
 * Total Accepted:    220.6K
 * Total Submissions: 816K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * Note:
 * 
 * 
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 * 
 */
class Solution {
public:


void rotate(vector<int>& nums, int k) {

	vector<int> temp;
	k %= nums.size();
	int count = 0;
	for (int i = nums.size() - 1; count < k; i--)
	{
		temp.push_back(nums[i]);
		count++;
	}


	for (int i = nums.size() - 1; i >= k; i--)
	{
		nums[i] = nums[i - k];
	}


	int index = 0;
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		nums[index] = temp[i];
		index++;
	}
}

    
    
};
