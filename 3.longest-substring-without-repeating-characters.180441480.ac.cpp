/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (25.05%)
 * Total Accepted:    593.4K
 * Total Submissions: 2.4M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    
    
int lengthOfLongestSubstring(string s) {

	if (s == "") return 0;
	int curMax = 0;
	int max = 0;
	int charset[256] = { 0 };
	int index = 0;
    
	while (s[index] != '\0')
	{
		char ch = s[index];
		if (charset[ch] == 0)
		{
			charset[ch] = index + 1;
			++curMax;
			if (curMax > max) max = curMax;
		}
		else
		{
			index = charset[ch] - 1;
            memset(charset, 0, sizeof(charset));
            curMax = 0;
		}
		index++;
	}
	return max;
}

};
