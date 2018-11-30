/*
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (48.02%)
 * Total Accepted:    102.2K
 * Total Submissions: 212.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 * 
 * Example:
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void sumOfLeftUtil(TreeNode* root, int& ans, char dir)
{
	if (root)
	{
		if (root->left == NULL && root->right == NULL && dir == 'l')
		{
			ans += root->val;
			return;
		}
		sumOfLeftUtil(root->left, ans, 'l');
		sumOfLeftUtil(root->right, ans, 'r');
	}
}

int sumOfLeftLeaves(TreeNode* root) {

	int ans = 0;
	char dir = 'n';
	sumOfLeftUtil(root, ans, dir);
	return ans;
}
};
