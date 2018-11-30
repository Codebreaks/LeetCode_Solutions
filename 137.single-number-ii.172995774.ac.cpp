/*
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (43.88%)
 * Total Accepted:    145.8K
 * Total Submissions: 332.4K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,3,2]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 * 
 */
class Solution {
public:
    
int singleNumber(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int counter = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] == nums[i - 1]) counter++;
        
		else if (counter == 3) counter = 1;
		
        else
		{
			if (i == 1)
			{
				return nums[0];
			}
			else
			{
				return nums[i-1];
			}
		}
	}
    
    return nums[nums.size()-1];
}
};
