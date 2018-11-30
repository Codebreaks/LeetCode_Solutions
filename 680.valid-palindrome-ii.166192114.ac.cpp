/*
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (32.56%)
 * Total Accepted:    44.8K
 * Total Submissions: 137.6K
 * Testcase Example:  '"aba"'
 *
 * 
 * Given a non-empty string s, you may delete at most one character.  Judge
 * whether you can make it a palindrome.
 * 
 * 
 * Example 1:
 * 
 * Input: "aba"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * 
 * Note:
 * 
 * The string will only contain lowercase characters a-z.
 * The maximum length of the string is 50000.
 * 
 * 
 */
class Solution {
public:
    
    bool palin(string s, int i, int j)
    {
        	while (i < j)
            {

                    if (s[i] == s[j])
                    {
                        i++;
                        j--;
                    }
                else 
                    return false;
            }
        return true;
    }
    
bool validPalindrome(string s) {
	bool missed = false;
	int i = 0;
	int j = s.size() - 1;
    
	while (i < j)
	{
		if (s[i] == s[j])
		{
			i++;
			j--;
		}
		else
		{
            int k = i++;
            int m = j--;
            return palin(s, k, j) ||  palin(s, i, m);

		}
	}
	return true;
    }
};
