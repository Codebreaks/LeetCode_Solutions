/*
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (32.20%)
 * Total Accepted:    233.5K
 * Total Submissions: 725.2K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
class Solution {
public:
    
int Binary(vector<int>& nums, int target, int l, int h)
{
	if (l <= h)
	{
		int mid = l + (h - l) / 2;
		if (nums[mid] == target) return mid;

		if (target < nums[mid])
		{
			return Binary(nums, target, l, mid - 1);
		}
		else
			return  Binary(nums, target, mid + 1, h);

	}
	return -1;
}

vector<int> searchRange(vector<int>& nums, int target) 
{
	vector<int> ans{-1,-1};
	int exists = Binary(nums, target, 0, nums.size() - 1);

	if (exists > -1)
	{
		ans[0] = ans[1] = exists;

		int llow = 0, lhigh = exists - 1;

		while (llow <= lhigh)
		{
			int temp = Binary(nums, target, llow, lhigh);
			if (temp != -1)
			{
				ans[0] = temp;
			}
			int mid = ((llow + lhigh) / 2);
			if (target <= nums[mid]) lhigh = mid - 1;
			else
				llow = mid + 1;
		}


		int rlow = exists+1, rhigh = nums.size()-1;

		while (rlow <= rhigh)
		{
			int temp = Binary(nums, target, rlow, rhigh);
			if (temp != -1)
			{
				ans[1] = temp;
			}
			int mid = ((rlow + rhigh) / 2);
			if (target >= nums[mid]) rlow = mid + 1;
			else
				rhigh = mid - 1;
		}

	}

		return ans;

}
    
};
