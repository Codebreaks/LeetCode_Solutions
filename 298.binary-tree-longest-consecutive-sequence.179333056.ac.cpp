/*
 * [298] Binary Tree Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (42.67%)
 * Total Accepted:    52.7K
 * Total Submissions: 123.6K
 * Testcase Example:  '[1,null,3,2,4,null,null,null,5]'
 *
 * Given a binary tree, find the length of the longest consecutive sequence
 * path.
 * 
 * The path refers to any sequence of nodes from some starting node to any node
 * in the tree along the parent-child connections. The longest consecutive path
 * need to be from parent to child (cannot be the reverse).
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   / \
 * ⁠  2   4
 * ⁠       \
 * ⁠        5
 * 
 * Output: 3
 * 
 * Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 
 * ⁠  2
 * ⁠   \
 * ⁠    3
 * ⁠   / 
 * ⁠  2    
 * ⁠ / 
 * ⁠1
 * 
 * Output: 2 
 * 
 * Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return
 * 2.
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
 int maxNum = 0;

 void longestConsecutive2(TreeNode* root, int start)
 {
	 maxNum = max(maxNum, start);
     // cout << maxNum << "\t";
	 int k = root->val;

	 if (root->left)
	 {
		 if (root->left->val == k + 1) {
			 longestConsecutive2(root->left, start+1);
		 }
         else
             longestConsecutive2(root->left, 1);
		 
	 }

	 if (root->right)
	 {
		 if (root->right->val == k + 1) {
			longestConsecutive2(root->right, start+1);
		 }
         else
		    longestConsecutive2(root->right, 1);
	 }
 }

 int longestConsecutive(TreeNode* root) 
 {
	 if (root)
	 {
		 int start = 1;
		 longestConsecutive2(root, start);
		 return maxNum;
	 }
	 return 0;
 }
};
