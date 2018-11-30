/*
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (39.96%)
 * Total Accepted:    304.8K
 * Total Submissions: 762.8K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
class Solution {
public:
int searchInsertBinary(vector<int>& nums, int l, int h, int target)
{
	if (l <= h )
	{
		int mid = (l + h) / 2;
        // cout << "mid" << mid;
		if (nums[mid] == target) return mid;
        
		if (target < nums[mid]) return searchInsertBinary(nums, 0, mid - 1, target);
		else
			return searchInsertBinary(nums, mid + 1,h , target);
	}
	return l;
}

int searchInsert(vector<int>& nums, int target) 
{
	return searchInsertBinary(nums, 0, nums.size()-1, target);
}
};
