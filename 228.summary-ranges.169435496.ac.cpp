/*
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (33.67%)
 * Total Accepted:    111K
 * Total Submissions: 329.6K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 * 
 * Example 1:
 * 
 * 
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 * 
 * 
 */
class Solution {
public:

vector<string> summaryRanges(vector<int>& nums) 
{
	vector<string> ans;
	if (nums.size())
	{
		int start = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if ((nums[i] - nums[i-1]) == 1) continue;
			else
			{
				if ((nums[i-1] - start) > 0)
				{
					ans.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
				}
				else
				{
					ans.push_back(to_string(start));
				}
				start = nums[i];
			}
		}

		if (start != nums[nums.size() - 1])
		{
			ans.push_back(to_string(start) + "->" + to_string(nums[nums.size() - 1]));
		}
		else
		{
			ans.push_back(to_string(start));
		}
	}
	return ans;
}
};
