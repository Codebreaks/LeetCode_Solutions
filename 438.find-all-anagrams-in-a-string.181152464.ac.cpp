/*
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Easy (34.46%)
 * Total Accepted:    81.7K
 * Total Submissions: 237K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 * 
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 * 
 * The order of output does not matter.
 * 
 * Example 1:
 * 
 * Input:
 * s: "cbaebabacd" p: "abc"
 * 
 * Output:
 * [0, 6]
 * 
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s: "abab" p: "ab"
 * 
 * Output:
 * [0, 1, 2]
 * 
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 */
class Solution {
public:

int getAnaIndes(string source, string pattern)
{

	int patIndex[256] = {0};

	for (int i = 0; i < source.size(); i++)
	{
		patIndex[source[i]]++;
	}

	for (int i = 0; i < pattern.size(); i++)
	{
		patIndex[pattern[i]]--;
        
        // cout << patIndex[pattern[i]] << "\t";
                         
		if (patIndex[pattern[i]] < 0) return -1;

	}

	return 1;
}

vector<int> findAnagrams(string s, string p)
{
	vector<int> ans;
    
    if(s.size() < p.size())
        return ans;

	int offset = p.size();
    int i = 0;

	while (i <= s.size() - offset)
	{

		if (getAnaIndes(s.substr(i, offset), p) != -1)
		{
			ans.push_back(i);
		}
		i++;
	}
	return ans;
}
};
