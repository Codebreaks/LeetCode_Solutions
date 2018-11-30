/*
 * [792] Binary Search
 *
 * https://leetcode.com/problems/binary-search/description/
 *
 * algorithms
 * Easy (36.89%)
 * Total Accepted:    12.5K
 * Total Submissions: 33.9K
 * Testcase Example:  '[-1,0,3,5,9,12]\n9'
 *
 * Given a sorted (in ascending order) integer array nums of n elements and a
 * target value, write a function to search target in nums. If target exists,
 * then return its index, otherwise return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all elements in nums are unique.
 * n will be in the range [1, 10000].
 * The value of each element in nums will be in the range [-9999, 9999].
 * 
 * 
 */
class Solution {
public:
int Binary(vector<int>& nums, int target, int l, int h)
{
	if(l <= h)
	{ 
		int mid = l + (h - l) / 2;
		if (nums[mid] == target) return mid;

		if (target < nums[mid])
		{
			return Binary(nums, target, l, mid-1);
		}
		else
				return  Binary(nums, target, mid+1, h);

	}
	return -1;
}

int search(vector<int>& nums, int target) {
	
	return Binary(nums, target, 0, nums.size() - 1);
}
};
