/*
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (32.73%)
 * Total Accepted:    38.3K
 * Total Submissions: 117K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the
 * root.
 * 
 * Note: The length of path between two nodes is represented by the number of
 * edges between them.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 * 
 * 
 * 
 * 
 * Output:
 * 
 * 2
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 * 
 * 
 * 
 * 
 * Output:
 * 
 * 2
 * 
 * 
 * 
 * Note:
 * The given binary tree has not more than 10000 nodes.  The height of the tree
 * is not more than 1000.
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
    int unitree = 0;

 int countUnivalSubtrees2(TreeNode* root)
 {
	 int left, right;
	 bool l, r;

	 left = right = 0;
	 l = r = false;

	 if (root->left)
	 {
		 left = countUnivalSubtrees2(root->left);
		 l = root->val == root->left->val ? true : false;
	 }

	 if (root->right) {

		 right = countUnivalSubtrees2(root->right);
		 r = root->val == root->right->val ? true : false;
	 }

	 if (!root->left && !root->right)
	 {
		 return 0;
	 }
	 else
	 {
		 int ret = 0;
		 if (l)
		 {
			 ret += left;
			 ret += 1;

		 }
		 if (r)
		 {
			 ret += right;
			 ret += 1;
		 }

		 unitree = max(ret, unitree);

		 if (l&r)
			 return max(left, right) + 1;
		 else
			 if (l)
				 return left + 1;
			 else if (r)
				 return right + 1;
			 else
				 return 0;
	 }
 }

 int longestUnivaluePath(TreeNode* root) {

	 if (!root) return unitree;
	 countUnivalSubtrees2(root);
	 return unitree;
 }

};
