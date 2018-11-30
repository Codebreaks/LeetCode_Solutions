/*
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (45.18%)
 * Total Accepted:    84.5K
 * Total Submissions: 187.1K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 * 
 * 
 * 
 * Example:
 * Given a binary tree 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * 
 * 
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 * 
 * 
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
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
    
int maxDepth(TreeNode* root) {
	if (root)
	{
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
	return 0;
}
    
    
// int diameterOfBinaryTree(TreeNode* root) 
// {
// 	if (root)
// 	{
// 		int lht = maxDepth(root->left);
// 		int rht = maxDepth(root->right);
// 		int dia = lht + rht;
// 		int ldia = diameterOfBinaryTree(root->left);
// 		int rdia = diameterOfBinaryTree(root->right);
// 		return max(dia, max(ldia, rdia));
// 	}
// 	return 0;
// }
    
    int maxdia = 0;

int diameterOfBinaryTree2(TreeNode* root)
{
	if (root)
	{
		int ldia = diameterOfBinaryTree(root->left);
		int rdia = diameterOfBinaryTree(root->right);
		int lht = maxDepth(root->left);
		int rht = maxDepth(root->right);
		int dia = lht + rht;
		maxdia = max(maxdia, dia);
		return max(ldia, rdia);
	}
	return 0;

}

int diameterOfBinaryTree(TreeNode* root)
{
	diameterOfBinaryTree2(root);
	return maxdia;
}
    
};
