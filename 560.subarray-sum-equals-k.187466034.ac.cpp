/*
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (40.38%)
 * Total Accepted:    58.6K
 * Total Submissions: 145.1K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * 
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 
 * 
 * 
 * Note:
 * 
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 * 
 * 
 * 
 */
class Solution {
public:
    
//     sum to keep track of sum of all the elements so far. If we can find a prefix sum in the map for sum-k, it means we can form sum == k using the elements after the element corresponding to that prefix sum till the current element (included). Count all such sums at each element.
    
int subarraySum(vector<int>& nums, int k) {
	if (!nums.size()) return 0;
	map<int, int> sumcount{ { 0,1 } };
	map<int, int>::iterator itr;
	int count = 0;
	int sumSoFar = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		sumSoFar += nums[i];

		if (sumcount.find(sumSoFar - k) != sumcount.end())
		{
			count += sumcount.find(sumSoFar - k)->second;
		}

		if (sumcount.find(sumSoFar) == sumcount.end())
		{
			sumcount.insert(pair<int,int> (sumSoFar, 1));
		}
		else
		{
			sumcount.find(sumSoFar)->second  = sumcount.find(sumSoFar)->second + 1;
		}
	}
	return count;
}
    
    
    
};
