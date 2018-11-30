/*
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (51.04%)
 * Total Accepted:    136.1K
 * Total Submissions: 266.7K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */
class Solution {
public:
vector<int> topKFrequent(vector<int>& nums, int k) 
{
	vector<int> result;
	if (!nums.size()) return result;
	unordered_map<int, int> counter;
	unordered_map<int, int>::iterator itr;
	multimap<int, int>::reverse_iterator itr2;
	typedef pair<int, int> pr;

	for (auto x : nums)
	{
		itr = counter.find(x);
		if (itr == counter.end())
			counter.insert(pr(x, 1));
		else
			itr->second += 1;
	}

	itr = counter.begin();
    
	multimap<int, int> orderedMap;
    
    cout<<counter.size();
    
	while (itr != counter.end())
	{
		orderedMap.insert(pr(itr->second, itr->first));
		itr++;
	}

	itr2 = orderedMap.rbegin();

	while (k)
	{
		
		result.push_back(itr2->second);
		itr2++;
		k--;
	}
	return result;
}
};
