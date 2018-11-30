/*
 * [742] To Lower Case
 *
 * https://leetcode.com/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (74.29%)
 * Total Accepted:    32.4K
 * Total Submissions: 43.6K
 * Testcase Example:  '"Hello"'
 *
 * Implement function ToLowerCase() that has a string parameter str, and
 * returns the same string in lowercase.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "Hello"
 * Output: "hello"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "here"
 * Output: "here"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "LOVELY"
 * Output: "lovely"
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
string toLowerCase(string str) {

	if (str.size() != 0)
	{
		for (int i = 0; i < str.size(); i++)
		{
			str[i] = tolower(str[i]);
		}
	}
	return str;
}
};
