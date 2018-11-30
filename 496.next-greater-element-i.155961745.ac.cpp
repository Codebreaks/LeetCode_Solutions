/*
 * [496] Next Greater Element I
 *
 * https://leetcode.com/problems/next-greater-element-i/description/
 *
 * algorithms
 * Easy (57.07%)
 * Total Accepted:    69.7K
 * Total Submissions: 122.1K
 * Testcase Example:  '[4,1,2]\n[1,3,4,2]'
 *
 * 
 * You are given two arrays (without duplicates) nums1 and nums2 where nums1’s
 * elements are subset of nums2. Find all the next greater numbers for nums1's
 * elements in the corresponding places of nums2. 
 * 
 * 
 * 
 * The Next Greater Number of a number x in nums1 is the first greater number
 * to its right in nums2. If it does not exist, output -1 for this number.
 * 
 * 
 * Example 1:
 * 
 * Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
 * Output: [-1,3,-1]
 * Explanation:
 * ⁠   For number 4 in the first array, you cannot find the next greater number
 * for it in the second array, so output -1.
 * ⁠   For number 1 in the first array, the next greater number for it in the
 * second array is 3.
 * ⁠   For number 2 in the first array, there is no next greater number for it
 * in the second array, so output -1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: nums1 = [2,4], nums2 = [1,2,3,4].
 * Output: [3,-1]
 * Explanation:
 * ⁠   For number 2 in the first array, the next greater number for it in the
 * second array is 3.
 * ⁠   For number 4 in the first array, there is no next greater number for it
 * in the second array, so output -1.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * All elements in nums1 and nums2 are unique.
 * The length of both nums1 and nums2 would not exceed 1000.
 * 
 * 
 */
class Solution {
public:
    
    
vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {

	unordered_map<int, int> holder;
	unordered_map<int, int>::iterator it;
	vector<int> result;

	for (int i = 0; i < nums.size(); i++)
	{
		holder.insert(pair<int, int>(nums[i], i));
	}

	for (int i = 0; i < findNums.size(); i++)
	{
		it = holder.find(findNums[i]);
		int index = it->second;
        index++;
		bool found = false;

		while (index < nums.size())
		{
			if (nums[index] > findNums[i])
			{
				result.push_back(nums[index]);
				found = true;
				break;
			}
			index++;
		}

		if (!found)
		{
			result.push_back(-1);
		}
	}

	return result;
}
    
    
};
