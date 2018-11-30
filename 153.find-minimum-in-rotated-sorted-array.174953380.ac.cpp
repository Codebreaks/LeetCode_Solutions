/*
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (41.66%)
 * Total Accepted:    226K
 * Total Submissions: 542.5K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
 * 
 */
class Solution {
public:
int searchRotated2(vector<int>& nums, int l, int h)
{
	if (nums[l] < nums[h]) return nums[l];
	int mid = (l + h) / 2;
	if ((mid == l) && (nums[mid] < nums[mid + 1])) return nums[mid];
	if ((mid == h) && (nums[mid] <  nums[mid - 1])) return nums[mid];
	if ((nums[mid] < nums[mid+1]) && (nums[mid] < nums[mid - 1])) return nums[mid];

	if (nums[l] <= nums[mid]) //left is sorted so search in right
	{

			return searchRotated2(nums, mid + 1, h);

	}
	else // right is sorted so search in left
	{

			return searchRotated2(nums, l, mid - 1);

	}
}

int findMin(vector<int>& nums) {
	return searchRotated2(nums, 0, nums.size() - 1);
}
};
