/*
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (46.48%)
 * Total Accepted:    75.7K
 * Total Submissions: 162.8K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 */
class Solution {
public:
    int longestPalindrome(string s) {
        
        if (s == "") return 0;
		int indexes[256] = { 0 };

		int i = 0;
		int evencount = 0;
        bool oddfound = false;

		while (i  < s.size())
		{
			indexes[s[i]]++;
            i++;
		}
        
        i = 0;
		while (i  < s.size())
		{
			if (indexes[s[i]] % 2 == 0)
			{
				evencount += indexes[s[i]];
                
			}
            else
            {
                evencount += (indexes[s[i]] - 1);
                oddfound = true;
            }
            indexes[s[i]] = 0;
            i++;
		}
		if (oddfound)
		{
			return evencount + 1;
		}
		else
		{
			return evencount;
		}
        
    }
};
