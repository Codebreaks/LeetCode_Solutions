/*
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (38.76%)
 * Total Accepted:    56.9K
 * Total Submissions: 146.8K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 * 
 * 
 * Note:
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 */
class Solution {
public:

bool canPartition(vector<int>& nums) 
{
	sort(nums.begin(), nums.end());
	//reverse(nums.begin(), nums.end());
	int sum1 = 0;
	int sum2 = 0;

	if (nums.size() == 1) return false;

	if (nums.size() > 1)
	{
		sum1 = nums[nums.size() - 1];
		sum2 = nums[nums.size() - 2];
	}

	for (int i = nums.size()-3; i >= 0; i--)
	{
		if (sum1 > sum2)
		{
			sum2 += nums[i];
		}
		else
		{
			sum1 += nums[i];
		}
	}

	if (sum1 == sum2) return true;
	else 
		return false;

}
    
};
