/*
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (43.61%)
 * Total Accepted:    163.5K
 * Total Submissions: 375K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
class Solution {
public:
void VecCombine(int start, int max, int k, vector<vector<int>>& ans, vector<int> list)
{
	if (k == 0)
	{
		ans.push_back(list);
		return;
	}

	for (int i = start; i <= max; i++)
	{

		list.push_back(i);
		VecCombine(i + 1, max, k - 1, ans, list);
		list.pop_back();
	}
}

vector<vector<int>> combine(int n, int k) 
{
	vector<vector<int>> ans;
	vector<int> temp;
	VecCombine(1, n, k, ans, temp);
	return ans;
}
};
