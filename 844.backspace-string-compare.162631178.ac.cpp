/*
 * [874] Backspace String Compare
 *
 * https://leetcode.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (43.55%)
 * Total Accepted:    19.2K
 * Total Submissions: 44.1K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * Given two strings S and T, return if they are equal when both are typed into
 * empty text editors. # means a backspace character.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S and T only contain lowercase letters and '#' characters.
 * 
 * 
 * Follow up:
 * 
 * 
 * Can you solve it in O(N) time and O(1) space?
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
bool backspaceCompare(string S, string T) {
	stack<char> sStack;
	stack<char> tStack;

	int i = 0;
	while(S[i] != '\0')
	{
		if (S[i] != '#')
		{
			sStack.push(S[i]);
		}
		else
		{
			if(!sStack.empty())
            sStack.pop();
		}
		i++;
	}

	i = 0;
	while (T[i] != '\0')
	{
		if (T[i] != '#')
		{
			tStack.push(T[i]);
		}
		else
		{
			if(!tStack.empty())
            tStack.pop();
		}
		i++;
	}
	if (sStack.size() == tStack.size())
	{
		while (!sStack.empty())
		{
			char sTop = sStack.top();
			char tTop = tStack.top();
			if (sTop != tTop) return false;
			sStack.pop();
			tStack.pop();
		}
		return true;
	}
	return false;
}
};
