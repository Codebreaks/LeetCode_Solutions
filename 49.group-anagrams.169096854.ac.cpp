/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (41.50%)
 * Total Accepted:    242.4K
 * Total Submissions: 584.2K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */
class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
	unordered_map<string, vector<string>> maps;

	for (int i = 0; i < strs.size(); i++)
	{
		string temp = strs[i];
		sort(temp.begin(), temp.end());

		unordered_map<string, vector<string>>::iterator itr;

		itr = maps.find(temp);

		if (itr == maps.end())
		{
			maps.insert(pair<string, vector<string>>(temp, vector<string>(1, strs[i])));
		}
		else
		{
			itr->second.push_back(strs[i]);
		}
	}

	unordered_map<string, vector<string>>::iterator itr;
	itr = maps.begin();
	vector<vector<string>> ans;
	while (itr != maps.end())
	{
		ans.push_back(itr->second);
        itr++;
	}
	return ans;
}
};
