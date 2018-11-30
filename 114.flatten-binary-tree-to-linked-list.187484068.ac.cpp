/*
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (39.24%)
 * Total Accepted:    197K
 * Total Submissions: 502K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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

 TreeNode* flattenRet(TreeNode* root)
 {
	 if (!root) return NULL;

	 TreeNode* rightBranch = NULL;

	 if (root->right)
		 rightBranch = root->right;


    root->right = flattenRet(root->left);
    root->left = NULL;
	

	 if (rightBranch)
	 {
         TreeNode* roottemp = root;
         while (roottemp->right != NULL) roottemp = roottemp->right;
         roottemp->right = flattenRet(rightBranch);
	 }
     
	 return root;
 }


 void flatten(TreeNode* root) 
 {
	 flattenRet(root);
 }
    
};
