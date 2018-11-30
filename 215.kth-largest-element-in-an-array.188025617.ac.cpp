/*
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (43.60%)
 * Total Accepted:    273.3K
 * Total Submissions: 626.8K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */
class Solution {
public:
//     int findKthLargest(vector<int>& nums, int k) {
        
        
//         sort(nums.begin(), nums.end());
//         return(nums[nums.size()-k]);
        
//     }
    
// Priority Q implementation.
int findKthLargest(vector<int>& nums, int k) 
{
	priority_queue<int, std::vector<int>, std::greater<int> > maxkelemetns;

	for (int a : nums)
	{
		if (maxkelemetns.size() < k)
		{
			maxkelemetns.push(a);
		}
		else
		{
			if (a > maxkelemetns.top())
			{
				maxkelemetns.pop();
				maxkelemetns.push(a);
			}
		}
	}
	return maxkelemetns.top();
}
};
