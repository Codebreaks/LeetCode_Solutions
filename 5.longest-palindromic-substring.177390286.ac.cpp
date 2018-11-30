/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.60%)
 * Total Accepted:    381.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
// bool isPalindrome(int start, int end, string str)
// {
// 	while (start<end)
// 	{
// 		if (str[start] == str[end])
// 		{
// 			start++;
// 			end--;
// 		}
// 		else
// 		{
// 			return false;
// 		}
// 	}
// 	return true;
// }

// string longestPalindrome(string s) {
    
//   if (s.size() <= 1) return s;


// 	int maxsize = INT_MIN;
// 	string returnstring = s.substr(0, 1);

// 	for (int i = 0; i < s.size()-1; i++)
// 	{
// 		for (int j = i+1; j < s.size(); j++)
// 		{
// 			if (isPalindrome(i,j,s))
// 			{
// 				if ((j-i+1) > maxsize)
// 				{
// 					maxsize = (j - i + 1);
// 					returnstring = s.substr(i, maxsize);
// 				}
// 			}
// 		}
// 	}
// 	return returnstring;
// }
    
    string longestPalindrome(string s) {
    if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {
      if (s.size() - i <= max_len / 2) break;
      int j = i, k = i;
      while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
      i = k+1;
      while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
      int new_len = k - j + 1;
      if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
}
};
