/*
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (44.83%)
 * Total Accepted:    282.8K
 * Total Submissions: 630.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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
vector<vector<int>> levelOrder(TreeNode* root) {

	vector<vector<int>> result;
	queue<TreeNode*> myqueue;

	if (root)
	{
		myqueue.push(root);
		int count = myqueue.size();
		while (count)
		{
			vector<int> temp;
			while (count)
			{
				TreeNode* poproot = myqueue.front();
				if (poproot->left)myqueue.push(poproot->left);
				if (poproot->right)myqueue.push(poproot->right);
				temp.push_back(poproot->val);
                myqueue.pop();
                --count;
			}
			result.push_back(temp);
			count = myqueue.size();
		}
	}
	return result;
}
};
