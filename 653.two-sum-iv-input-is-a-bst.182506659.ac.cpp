/*
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (50.72%)
 * Total Accepted:    58.1K
 * Total Submissions: 114.5K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 * 
 * Example 1:
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 9
 * 
 * Output: True
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 28
 * 
 * Output: False
 * 
 * 
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
    
TreeNode* rtp = NULL;
TreeNode* head = NULL;
bool first = true;
    
bool searchBST(TreeNode* root, int val)
{
	if (root)
	{
		if (root->val == val) { rtp = root; return true;}

        bool r1 = false;
        bool r2 = false;
        
		if (root->left && val < root->val)
			r1 = searchBST(root->left, val);

		if (root->right && val > root->val)
			r2 = searchBST(root->right, val);

		return (r1 || r2);
	}
    
	return false;
}



bool findTarget(TreeNode* root, int k) 
{
	if(first) {head = root; first = false;}
    
    if (root)
	{
           if(searchBST(head, (k - root->val)))
           {
              if(rtp != root)   return true;
               
           }

        return (findTarget(root->left, k) || findTarget(root->right, k));
	}
	return false;
}
    
};
