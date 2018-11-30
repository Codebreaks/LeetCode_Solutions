/*
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (61.50%)
 * Total Accepted:    301.6K
 * Total Submissions: 490.4K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: "hello"
 * Output: "olleh"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: "amanaP :lanac a ,nalp a ,nam A"
 * 
 * 
 * 
 * 
 */
class Solution {
public:
string reverseString(string s) {

	int l = 0;
	int h = s.size()-1;

	while (l < h)
	{
		char temp = s[l];
		s[l++] = s[h];
		s[h--] = temp;
	}
	return s;
}
    
};
