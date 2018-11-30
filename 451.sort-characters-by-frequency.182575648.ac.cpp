/*
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (52.96%)
 * Total Accepted:    67.2K
 * Total Submissions: 126.9K
 * Testcase Example:  '"tree"'
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 * 
 * Example 1:
 * 
 * Input:
 * "tree"
 * 
 * Output:
 * "eert"
 * 
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * "cccaaa"
 * 
 * Output:
 * "cccaaa"
 * 
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:
 * "Aabb"
 * 
 * Output:
 * "bbAa"
 * 
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 * 
 * 
 */
class Solution {
public:
string frequencySort(string s) {

	multimap<int,char> dict;
	multimap<int, char>::reverse_iterator rit;

	map<char, int> orgmap;
	map<char, int>::iterator itr;

	for (int i = 0; i < s.size(); i++)
	{
		itr = orgmap.find(s[i]);

		if (itr != orgmap.end())
		{
			itr->second = itr->second + 1;
		}
		else
		{
			orgmap.insert(pair<char, int>(s[i], 1));
		}
	}

	itr = orgmap.begin();
	while (itr != orgmap.end())
	{
		dict.insert(pair<int, char>(itr->second, itr->first));
		itr++;
	}

	rit = dict.rbegin();

	string ans = "";
	
	while (rit != dict.rend())
	{
		int count = rit->first;

		while (count)
		{
			ans += rit->second;
			count--;
		}
		rit++;
	}
	return ans;
}
};
