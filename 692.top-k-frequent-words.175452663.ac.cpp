/*
 * [692] Top K Frequent Words
 *
 * https://leetcode.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (42.52%)
 * Total Accepted:    33.3K
 * Total Submissions: 78.3K
 * Testcase Example:  '["i", "love", "leetcode", "i", "love", "coding"]\n2'
 *
 * Given a non-empty list of words, return the k most frequent elements.
 * Your answer should be sorted by frequency from highest to lowest. If two
 * words have the same frequency, then the word with the lower alphabetical
 * order comes first.
 * 
 * Example 1:
 * 
 * Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * Output: ["i", "love"]
 * Explanation: "i" and "love" are the two most frequent words.
 * ⁠   Note that "i" comes before "love" due to a lower alphabetical order.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is",
 * "is"], k = 4
 * Output: ["the", "is", "sunny", "day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent
 * words,
 * ⁠   with the number of occurrence being 4, 3, 2 and 1 respectively.
 * 
 * 
 * 
 * Note:
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Input words contain only lowercase letters.
 * 
 * 
 * 
 * Follow up:
 * 
 * Try to solve it in O(n log k) time and O(n) extra space.
 * 
 * 
 */
class Solution {
public:
vector<string> topKFrequent(vector<string>& words, int k) 
{
	vector<string> result;
	if (!words.size()) return result;
	unordered_map<string, int> counter;
	unordered_map<string, int>::iterator itr;
	multimap<int, string>::reverse_iterator itr2;
	typedef pair<string, int> pr;
	typedef pair<int,string> pr2;

	for (auto x : words)
	{
		itr = counter.find(x);
		if (itr == counter.end())
			counter.insert(pr(x, 1));
		else
			itr->second += 1;
	}

	itr = counter.begin();
	multimap<int, string> orderedMap;
	while (itr != counter.end())
	{
		orderedMap.insert(pr2(itr->second, itr->first));
		itr++;
	}

	itr2 = orderedMap.rbegin();
	
	vector<string> holder;


	int count = itr2->first;

	while (itr2 != orderedMap.rend() && k)
	{
		if (count == itr2->first)
		{
			holder.push_back(itr2->second);
			itr2++;
		}
		else
		{
			sort(holder.begin(), holder.end());
			for (auto x : holder)
			{
				result.push_back(x);
				k--;
				if (!k) break;
			}
			holder.clear();
			count = itr2->first;
		}

	}
    
    	sort(holder.begin(), holder.end());
	for (auto x : holder)
	{
		result.push_back(x);
		k--;
		if (!k) break;
	}

	return result;
}
};
