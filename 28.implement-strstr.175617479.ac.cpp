/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (30.01%)
 * Total Accepted:    321.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
class Solution {
public:
int strStr(string haystack, string needle) 
{
	if (!haystack.size() && !needle.size()) return 0;
    
    if (!haystack.size()) return -1;
    
    if(haystack.size() < needle.size()) return -1;

    int j = 0;
	for (int i = 0; i <= (haystack.size() - needle.size()); i++)
	{
		for (j = 0; j < needle.size(); j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (j == needle.size()) return i;
	}
	return -1;
}
};
