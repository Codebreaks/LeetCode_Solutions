/*
 * [448] Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (51.47%)
 * Total Accepted:    111K
 * Total Submissions: 215.8K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some
 * elements appear twice and others appear once.
 * 
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * 
 * Could you do it without extra space and in O(n) runtime? You may assume the
 * returned list does not count as extra space.
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [5,6]
 * 
 * 
 */
class Solution {
public:
    
bool KeyFound(vector<int>& nums, int key, int low, int high)
{
	if (low <= high)
	{
		int mid = ((high - low) / 2) + low;
		if (nums[mid] == key) return true;
		else if (key < nums[mid]) return KeyFound(nums, key, low, mid-1);
		else return KeyFound(nums, key, mid+1, high);
	}
	return false;
}

vector<int> findDisappearedNumbers(vector<int>& nums) {

	vector<int> result;
	sort(nums.begin(), nums.end());
	
	int num = nums.size();

	while (num)
	{
		if (!KeyFound(nums, num, 0, nums.size())) result.push_back(num);
		--num;
	} 
	return result;
}
    
    
};
