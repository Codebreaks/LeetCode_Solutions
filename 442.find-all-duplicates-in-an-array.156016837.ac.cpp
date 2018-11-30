/*
 * [442] Find All Duplicates in an Array
 *
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (58.20%)
 * Total Accepted:    72.8K
 * Total Submissions: 125K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
 * appear twice and others appear once.
 * 
 * Find all the elements that appear twice in this array.
 * 
 * Could you do it without extra space and in O(n) runtime?
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [2,3]
 * 
 */
class Solution {
public:

vector<int> findDuplicates(vector<int>& nums) {

	vector<int> result;
	sort(nums.begin(), nums.end());
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i - 1] == nums[i]) result.push_back(nums[i]);
	}
	return result;

}
};
