/*
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (44.96%)
 * Total Accepted:    140.5K
 * Total Submissions: 312.4K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * 
 * 
 * Note:
 * 
 * 
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 * 
 * 
 * Follow up:
 * 
 * 
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 * 
 * 
 */
class Solution {
public:
    
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
{
	vector<int> results;
	set<int> unique;
	std::pair<std::set<int>::iterator, bool> ret;
	vector<int> position;

	
			for (int i = 0; i < nums1.size(); i++)
		{
			int one = nums1[i];

			for (int j = 0; j < nums2.size(); j++)
			{
				int two = nums2[j];
				
				if (one == two && (find(position.begin(), position.end(), j) == position.end()))
				{
					position.push_back(j);
					ret = unique.insert(one);
					cout << ret.second << endl;
					if (ret.second == false)
					{
						results.push_back(*ret.first);
					}
					break;
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
