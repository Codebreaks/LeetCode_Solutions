/*
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (28.39%)
 * Total Accepted:    181.3K
 * Total Submissions: 638.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
class Solution {
public:

vector<vector<int>> fourSum(vector<int>& nums, int target) {

	vector<vector<int>> ans;
	int maxsubsets = pow(2, nums.size());
	vector<int> holder = {0};
	int sum = 0;
	int j = 1;

	for (int i = 0; i < maxsubsets; i++)
	{
		for (int count = 0; count < nums.size(); count++)
		{
			if (i&j)
			{
				holder.push_back(nums[count]);
				sum += nums[count];
			}
			j = j << 1;
			
		}
        
        // cout << sum <<"\t";
        // cout << holder.size() <<"\t";
        
		if ((holder.size() == 4) && (sum == target))
		{
			ans.push_back(holder);
		}
        
		sum = 0;
		holder.clear();
        j = 1;
	}
	return ans;
}
};
