/*
 * [855] Unique Letter String
 *
 * https://leetcode.com/problems/unique-letter-string/description/
 *
 * algorithms
 * Hard (35.70%)
 * Total Accepted:    3K
 * Total Submissions: 8.4K
 * Testcase Example:  '"ABC"'
 *
 * A character is unique in string S if it occurs exactly once in it.
 * 
 * For example, in string S = "LETTER", the only unique characters are "L" and
 * "R".
 * 
 * Let's define UNIQ(S) as the number of unique characters in string S.
 * 
 * For example, UNIQ("LETTER") =  2.
 * 
 * Given a string S with only uppercases, calculate the sum of UNIQ(substring)
 * over all non-empty substrings of S.
 * 
 * If there are two or more equal substrings at different positions in S, we
 * consider them different.
 * 
 * Since the answer can be very large, return the answer modulo 10 ^ 9 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "ABC"
 * Output: 10
 * Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
 * Evey substring is composed with only unique letters.
 * Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
 * 
 * Example 2:
 * 
 * 
 * Input: "ABA"
 * Output: 8
 * Explanation: The same as example 1, except uni("ABA") = 1.
 * 
 * 
 * 
 * 
 * Note: 0 <= S.length <= 10000.
 * 
 */
class Solution {
public:
    
int getUnique(string s)
{
	int index[256] = {0};
	int uincnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		index[s[i]]++;
		if (index[s[i]] == 1) uincnt++;
		if (index[s[i]] == 2) uincnt--;

	}
	return uincnt;
}

int uniqueLetterString(string S) 
{
	int sum = 0;
	for (int i = 0; i < S.size(); i++)
	{
		string str = S.substr(i, S.size() - i);

		for (int j = 0; j < str.size(); j++)
		{
			sum += getUnique(str.substr(j, str.size() - j));
		}
	}
	return sum % 1000000007;
}
};
