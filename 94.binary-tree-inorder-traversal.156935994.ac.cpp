/*
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (52.42%)
 * Total Accepted:    340.3K
 * Total Submissions: 649.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
void inorder(TreeNode* root, vector<int>& ans)
{
	if (root)
	{
		inorder(root->left, ans);
		ans.push_back(root->val);
		inorder(root->right, ans);
	}
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ans;
	inorder(root, ans);
	return ans;
}
};
