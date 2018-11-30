/*
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (54.63%)
 * Total Accepted:    91.1K
 * Total Submissions: 166.7K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 * 
 * Note:
 * 
 * 
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 * 
 * 
 */
class Solution {
public:

vector<int> singleNumber(vector<int>& nums) {

	vector<int> ans;
	
	sort(nums.begin(),nums.end());
    
	int first = 0;
	int second = 0;

	for (int i = 1; i < nums.size(); i++)
	{
		if ((nums[i] ^ nums[i-1]) == 0)
		{
			i++;
			if (i == (nums.size()-1))
			{
				ans.push_back(nums[i]);
				break;
			}
		}
		else
		{
			ans.push_back(nums[i - 1]);
		}
	}

	if (ans.size() == 1) ans.push_back(nums[nums.size()-1]);

	return ans;
}

};
