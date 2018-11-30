/*
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (38.53%)
 * Total Accepted:    163.8K
 * Total Submissions: 425K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> result;
	queue<TreeNode*> myqueue;
	bool invert = false;

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
			if (invert)
			{
				reverse(temp.begin(), temp.end());
			}
			result.push_back(temp);
			count = myqueue.size();
			invert = !invert;
		}
	}
	return result;
    }
};
