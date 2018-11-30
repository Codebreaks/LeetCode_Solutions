/*
 * [933] Increasing Order Search Tree
 *
 * https://leetcode.com/problems/increasing-order-search-tree/description/
 *
 * algorithms
 * Easy (57.30%)
 * Total Accepted:    8.1K
 * Total Submissions: 14.1K
 * Testcase Example:  '[5,3,6,2,4,null,8,1,null,null,null,7,9]'
 *
 * Given a tree, rearrange the tree in in-order so that the leftmost node in
 * the tree is now the root of the tree, and every node has no left child and
 * only 1 right child.
 * 
 * 
 * Example 1:
 * Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]
 * 
 * ⁠      5
 * ⁠     / \
 * ⁠   3    6
 * ⁠  / \    \
 * ⁠ 2   4    8
 * /        / \ 
 * 1        7   9
 * 
 * Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 * 
 * ⁠1
 * \
 * 2
 * \
 * 3
 * \
 * 4
 * \
 * 5
 * \
 * 6
 * \
 * 7
 * \
 * 8
 * \
 * ⁠                9  
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given tree will be between 1 and 100.
 * Each node will have a unique integer value from 0 to 1000.
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
    
    TreeNode* ansNode = NULL;
    
    void insertIntoBST(TreeNode* root, int val) {

	if (root)
	{
		if (root->left && val < root->val)
			insertIntoBST(root->left, val);

		else if (root->right && val > root->val)
			insertIntoBST(root->right, val);

		else
		{
			if (val < root->val)
				root->left = new TreeNode(val);
			else
				root->right = new TreeNode(val);
		}

	}
        else
        {
            ansNode = new TreeNode(val);
           
            
        }
	
}
    
    
    
 TreeNode* increasingBST2(TreeNode* root) 
 {
	 if (!root) return ansNode;

	if(root->left)
	increasingBST(root->left);
		 
	insertIntoBST(ansNode, root->val);
		 
	if(root->right)
	increasingBST(root->right);

	return ansNode;


 }
    
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
        if (!root) return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
    
    
};
