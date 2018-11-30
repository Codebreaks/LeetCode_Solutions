/*
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (28.62%)
 * Total Accepted:    269.4K
 * Total Submissions: 941.3K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
class Solution {
public:
bool isPalindrome(string s) {
	if (!s.size()) return true;
	int start, end;
	start = 0;
	end = s.size() - 1;
	while (start < end)
	{
				while (!isalnum(s[start]))
		{
			start++;
			if (start == s.size()) return true;
		}
		while (!isalnum(s[end])) end--;
        
		if (tolower(s[start]) != tolower(s[end])) return false;
        start++;
        end--;
	}
	return true;
}
};
