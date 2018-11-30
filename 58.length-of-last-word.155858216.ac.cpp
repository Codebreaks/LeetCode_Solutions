/*
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.06%)
 * Total Accepted:    215.9K
 * Total Submissions: 673.2K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s == "") return 0;
        
        int ptr = s.size() - 1;
		
        while (s[ptr] == ' ') ptr--;
        
		
		int ctr = 0;
        
		while (ptr > -1 && s[ptr] != ' ')
		{
			++ctr;
            --ptr;
		}
		return ctr;
	}
};
