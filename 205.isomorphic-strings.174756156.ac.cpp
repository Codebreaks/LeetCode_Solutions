/*
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (35.54%)
 * Total Accepted:    160.3K
 * Total Submissions: 450.9K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */
class Solution {
public:

bool isIsomorphic(string s, string t) {

	if (!s.size()) return true;
	int sunique[256] = { 0 };
	int tunique[256] = { 0 };
	int sSum, tSum;
	sSum = tSum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		sunique[s[i]] = 1;
		tunique[t[i]] = 1;
	}

	for (auto x : sunique) {
		sSum += x;
	}

	for (auto x : tunique) {
		tSum += x;
	}

	if (sSum != tSum) return false;

	multimap<char, char> charmap;
	typedef pair<char, char> pr;
	multimap<char, char>::iterator itr;

	int index = 0;
	while (s[index] != '\0')
	{
		itr = charmap.find(s[index]);

		if (itr == charmap.end())
		{
			/*if (charmap.find(t[index]) != charmap.end() && charmap.find(t[index])->second == t[index]) return false;*/

			charmap.insert(pr(s[index], t[index]));
		}
		else
		{
			if (itr->second != t[index])
				return false;
		}
		index++;
	}
	return true;


}

    
};
