/*
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (41.46%)
 * Total Accepted:    299.8K
 * Total Submissions: 723.3K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3]  is not:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
bool isSymmetric2(TreeNode* left, TreeNode* right)
{
	if (left == NULL && right == NULL) return true;

	if (left && right)
	{
		if (left->val == right->val)
		{
			return isSymmetric2(left->left, right->right) && isSymmetric2(left->right, right->left);
		}
		else
			return false;
	}
	return false;
}

bool isSymmetric(TreeNode* root) {

	if (!root) return true;
	return isSymmetric2(root->left, root->right);
}
};
