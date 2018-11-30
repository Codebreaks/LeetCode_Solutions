/*
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (43.16%)
 * Total Accepted:    184.1K
 * Total Submissions: 426.6K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
void binaryTreePathsUtil(TreeNode* root, vector<string>& vec, string str)
{
	if (root)
	{
		if (!root->left && !root->right)
		{
			str += to_string(root->val);
			vec.push_back(str);
		}
		str = str + to_string(root->val) + "->";
		binaryTreePathsUtil(root->left, vec, str);
		binaryTreePathsUtil(root->right, vec, str);
	}
}

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> vec;
	string str = "";
	binaryTreePathsUtil(root, vec, str);
	return vec;
}
};
