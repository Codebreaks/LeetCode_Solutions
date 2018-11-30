/*
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (33.22%)
 * Total Accepted:    140.3K
 * Total Submissions: 422.3K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */
class Solution {
public:

int minSubArrayLen(int s, vector<int>& nums) 
{

	int curMin = 0;
	int min = INT_MAX;
	int sum = 0;

	for (int i = 0; i < nums.size(); i++)
	{

		for (int j = i; j < nums.size(); j++)
		{
			sum += nums[j];
			curMin++;

			if (sum >= s && curMin < min)
			{
				min = curMin;
                // cout << " MIN " << min << endl;
                // cout << " I " << i << " J " << j << endl;
				break;
			}
		}
        
        curMin = 0;
        sum = 0;
        curMin = 0;
	}
	return min == INT_MAX ? 0 : min;
    }
};
