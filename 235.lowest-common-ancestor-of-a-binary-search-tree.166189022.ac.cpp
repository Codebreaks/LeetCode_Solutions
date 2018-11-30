/*
 * [235] Lowest Common Ancestor of a Binary Search Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (41.40%)
 * Total Accepted:    223.2K
 * Total Submissions: 539K
 * Testcase Example:  '[6,2,8,0,4,7,9,null,null,3,5]\n2\n8'
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
 * 
 * 
 * ⁠       _______6______
 * ⁠      /              \
 * ⁠   ___2__          ___8__
 * ⁠  /      \        /      \
 * ⁠  0      _4       7       9
 * ⁠        /  \
 * ⁠        3   5
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant
 * of itself 
 * ⁠            according to the LCA definition.
 * 
 * 
 * Note:
 * 
 * 
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the BST.
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
bool isRreachable(TreeNode* root, TreeNode* p)
{
	if (root)
	{
		if (root->val == p->val) return true;
		if (p->val > root->val) return isRreachable(root->right, p);
		else
			return isRreachable(root->left, p);
	}
	return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	if(root)
	{ 
		if ((isRreachable(root->left, q) && isRreachable(root->right, p)) || ( isRreachable(root->left, p) && isRreachable(root->right, q)))
			return root;
		
		else if ((root->val == p->val) && (isRreachable(root->left, q) || isRreachable(root->right, q))) return root;

		else if ((root->val == q->val) && (isRreachable(root->left, p) || isRreachable(root->right, p))) return root;
		
		else
		{
			TreeNode* resultleft = NULL;
			TreeNode* resultright = NULL;

			if (root->left)
			{
				resultleft = lowestCommonAncestor(root->left, p, q);
				if (resultleft) return resultleft;
			}
			if (root->right)
			{
				resultright = lowestCommonAncestor(root->right, p, q);
				if (resultright)  return resultright;
			}
			return NULL;
		}
	}
	return root;
}

};
