/*
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (33.65%)
 * Total Accepted:    163.5K
 * Total Submissions: 485.8K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 * 
 * 
 * 
 * 
 */
class Solution {
public:
bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
	bool found = false;
	if (nums.size() < 2) return found;
	for (int i = 0; i < nums.size()-1; i++)
	{
		for (int j = i+1; j < nums.size(); j++)
		{
			if ((nums[i] == nums[j]) &&( abs(j-i) <= k)) 
			{
				found = true;
				break;
			}
		}
	}
	return found;
}
};
