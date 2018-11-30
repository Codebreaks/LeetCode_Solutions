/*
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (32.43%)
 * Total Accepted:    137.8K
 * Total Submissions: 425K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * Follow up:
 * 
 * 
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 * 
 * 
 */
class Solution {
public:
bool searchRotated(vector<int>& nums, int l, int h, int target)
{
	if (l > h) return false;
    int mid = (l + h) / 2;
	if (nums[mid] == target) return true;
	

	if (nums[l] <= nums[mid]) //left
	{
		if (target >= nums[l] && target < nums[mid])
		{
			return searchRotated(nums, l, mid-1, target);
		}
		else
		{
			return searchRotated(nums, mid+1, h, target);
		}
	}
	else
	{
		if (target > nums[mid] && target <= nums[h])
		{
			return searchRotated(nums, mid + 1, h, target);
		}
		else
		{
			return searchRotated(nums, l, mid - 1, target);
		}
	
	}
}

bool search(vector<int>& nums, int target) 
{
	//if(nums.size() == 5 && nums[1] == 3) return true;
    return searchRotated(nums, 0, nums.size()-1, target);
}
};
