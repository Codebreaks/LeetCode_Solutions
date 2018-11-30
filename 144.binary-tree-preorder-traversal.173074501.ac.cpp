/*
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (48.59%)
 * Total Accepted:    265.5K
 * Total Submissions: 546.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
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
vector<int> preorderTraversal(TreeNode* root) 
{
	stack<TreeNode*> holder;
	vector<int> ans;
	if (root)
	{
		holder.push(root);
		while (!holder.empty())
		{
			TreeNode* temp = holder.top();
			holder.pop();
			ans.push_back(temp->val);
			
			if (temp->right)
				holder.push(temp->right);

			if(temp->left)
				holder.push(temp->left);

		}
	}
	return ans;
}
};
