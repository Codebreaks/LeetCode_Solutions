/*
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (32.10%)
 * Total Accepted:    51K
 * Total Submissions: 158.7K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k.
 * 
 * Define a pair (u,v) which consists of one element from the first array and
 * one element from the second array.
 * 
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * Output: [[1,2],[1,4],[1,6]] 
 * Explanation: The first 3 pairs are returned from the sequence: 
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * Output: [1,1],[1,1]
 * Explanation: The first 2 pairs are returned from the sequence: 
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [1,2], nums2 = [3], k = 3
 * Output: [1,3],[2,3]
 * Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
 * 
 */
class Solution {
public:
vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
{
	
	vector<pair<int, int>> ans;
	if (!nums1.size()) return ans;
	if (!nums2.size()) return ans;
	sort(nums1.begin(), nums1.begin());
	sort(nums2.begin(), nums2.begin());



	int first = 0;
	int second = 0;
	int secondNest = second + 1;
	int fistNext = first + 1;

	while (k)
	{
		
		if (nums1[first] < nums2[second])
		{
			ans.push_back(pair<int, int>(nums1[first], nums2[second]));
			second++;
			k--;

			if (k && (second == nums2.size())) { second = 0; first++; }
			
		}
		else
		{
			ans.push_back(pair<int, int>(nums1[first], nums2[second]));
			first++;
			k--;

			if (k && (first == nums1.size())) { first = 0; second++; }

		}

	}
	return ans;
}
};
