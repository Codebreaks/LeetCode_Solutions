/*
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (43.38%)
 * Total Accepted:    165.9K
 * Total Submissions: 382.5K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
class Solution {
public:
int numTrees(int n) 
{
	n = n + 1;
    
    vector<int> cat(n+ 1, 0);
	cat[0] = 1;
	cat[1] = 1;
	for (int i = 2; i <= n; i++)
	{
        for (int j = 1; j < i; j++)
			cat[i] += cat[i - j] * cat[j];
	}
	return cat[n] ;
}
    
};
