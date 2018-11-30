/*
 * [503] Next Greater Element II
 *
 * https://leetcode.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (48.56%)
 * Total Accepted:    35K
 * Total Submissions: 72K
 * Testcase Example:  '[1,2,1]'
 *
 * 
 * Given a circular array (the next element of the last element is the first
 * element of the array), print the Next Greater Number for every element. The
 * Next Greater Number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, output -1 for this
 * number.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; The number 2 can't find
 * next greater number; The second 1's next greater number needs to search
 * circularly, which is also 2.
 * 
 * 
 * 
 * Note:
 * The length of given array won't exceed 10000.
 * 
 */
class Solution {
public:
    
    
vector<int> nextGreaterElements(vector<int>& nums) {

	vector<int> results;
	int size = nums.size();
	
	for (int i = 0; i < size; i++)
	{
		int target = nums[i];
		int index = (i + 1) % size;
		bool found = false;
		int counter = 0;
		while (counter < (size-1))
		{
			++counter;
			if (nums[index] > target)
			{
				found = true;
				results.push_back(nums[index]);
				break;
			}
			index = (index + 1) % size;
		}
		if (!found)
		{
			results.push_back(-1);
		}
	}
	return results;
}
    
    
};
