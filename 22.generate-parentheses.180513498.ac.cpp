/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (50.37%)
 * Total Accepted:    250.2K
 * Total Submissions: 496.6K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
void genparan(string s, int left, int right, vector<string>& ans)
{
	if (left == 0 && right ==0 )
	{
		ans.push_back(s);
		return;
	}
	if (left < 0 || right < 0 || left > right) return;

	genparan(s+"(", left-1, right, ans);
	genparan(s + ")", left, right - 1, ans);
}

vector<string> generateParenthesis(int n) {
	vector<string> ans;
	string str = "";
	genparan(str, n, n, ans );
	return ans;
}
};
