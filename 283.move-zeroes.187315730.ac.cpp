/*
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (52.42%)
 * Total Accepted:    350.4K
 * Total Submissions: 668.4K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 * 
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
//         vector<int> holder;
        
// 		for (int i = 0; i < nums.size(); i++)
// 		{
// 			if (nums[i])
// 			{
// 				holder.push_back(nums[i]);
// 			}
// 		}
		
//         int j;
        
// 		for (j = 0; j < holder.size(); j++)
// 		{
// 			nums[j] = holder[j];

// 		}

// 		while (j < nums.size())
// 		{
// 			nums[j] = 0;
//             j++;
// 		}
        



// 	int start = 0;
// 	int end = 0;

// 	while (start < nums.size())
// 	{
// 		while ( (start < nums.size()) &&  nums[start] != 0) start++;
// 		if (start == nums.size()) break;

// 		end = start + 1;
// 		while ((end < nums.size()) && nums[end] == 0) end++;
// 		if (end == nums.size()) break;

// 		nums[start] = nums[end];
// 		nums[end] = 0;
// 	}

        
        

	int index = 0;
	int nonzero = 0;

	while (true)
	{
		while (nonzero < nums.size() && !nums[nonzero]) nonzero++;
		if (nonzero == nums.size())break;
		nums[index++] = nums[nonzero++];
	}
	while (index < nums.size())
	{
		nums[index++] = 0;
	}

        
    }
};
