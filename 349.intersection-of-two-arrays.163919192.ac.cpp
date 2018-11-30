/*
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (49.94%)
 * Total Accepted:    160.8K
 * Total Submissions: 321.9K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * 
 * 
 * Note:
 * 
 * 
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    
    
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
	vector<int> results;
	set<int> unique;
	for (int i = 0; i < nums1.size(); i++)
	{
		int one = nums1[i];
		for (int j = 0; j < nums2.size(); j++)
		{
			int two = nums2[j];
			if (one == two)
			{
				unique.insert(one);
			}

		}
	}

	set<int>::iterator itr = unique.begin();

	while (itr != unique.end())
	{
		results.push_back(*itr);
		itr++;
	}
	return results;
}
    
    
};
