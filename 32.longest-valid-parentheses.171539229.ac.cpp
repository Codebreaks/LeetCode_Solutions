/*
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (24.09%)
 * Total Accepted:    152.7K
 * Total Submissions: 634K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */
class Solution {
public:
int longestValidParentheses(string s) 
{
	stack<int> holder;
	int max = 0;
	int curMax = 0;
    int pos = -1;
	int head = 0;

	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '(')
			holder.push(i);
		else
		{ 
			if (!holder.empty())
			{
				holder.pop();

				if (holder.empty())
					head = pos;
				else
					head = holder.top();

				curMax = i - head;
			}
			else
				pos = i;
		}
		max = max > curMax ? max : curMax;
        i++;
	}
	return max;
}
};
