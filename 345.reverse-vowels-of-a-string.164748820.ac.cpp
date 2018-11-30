/*
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (39.90%)
 * Total Accepted:    125K
 * Total Submissions: 313.3K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * Example 1:
 * 
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 * 
 * 
 */
class Solution {
public:

string reverseVowels(string s) {

	vector<int> pos;


	
	if (s.size() != 0)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'a' || s[i] == 'e' ||  s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
				|| s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
			{
				pos.push_back(i);
			}
		}
	}

	int start = 0;
	int end = pos.size()-1;
	while(start < end)
	{
		char temp = s[pos[start]];
		s[pos[start]] = s[pos[end]];
		s[pos[end]] = temp;
		start++;
		end--;
	}
	return s;
}
};
