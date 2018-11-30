/*
 * [186] Reverse Words in a String II
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-ii/description/
 *
 * algorithms
 * Medium (34.12%)
 * Total Accepted:    52.9K
 * Total Submissions: 155.1K
 * Testcase Example:  '["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]'
 *
 * Given an input string , reverse the string word by word. 
 * 
 * Example:
 * 
 * 
 * Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
 * Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
 * 
 * Note: 
 * 
 * 
 * A word is defined as a sequence of non-space characters.
 * The input string does not contain leading or trailing spaces.
 * The words are always separated by a single space.
 * 
 * 
 * Follow up: Could you do it in-place without allocating extra space?
 * 
 */
class Solution {
public:

void swapchar(int start, int end, vector<char>& str)
{
	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
        start++;
        end--;
	}
}

void reverseWords(vector<char>& str) {
	
	if (str.size() < 2) return;
	int start = 0;
	int end = start + 1;

	while (end < str.size())
	{
		while (end < str.size() && str[end] != ' ') end++;
        --end;
        
		swapchar(start, end, str);
        
		start = end + 2;
		end = start + 1;
	}
	reverse(str.begin(), str.end());
}
};
