/*
 * [513] Find Bottom Left Tree Value
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (56.92%)
 * Total Accepted:    55.3K
 * Total Submissions: 97.1K
 * Testcase Example:  '[2,1,3]'
 *
 * 
 * Given a binary tree, find the leftmost value in the last row of the tree. 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Output:
 * 1
 * 
 * 
 * 
 * ⁠ Example 2: 
 * 
 * Input:
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   5   6
 * ⁠      /
 * ⁠     7
 * 
 * Output:
 * 7
 * 
 * 
 * 
 * Note:
 * You may assume the tree (i.e., the given root node) is not NULL.
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
    
	int height(TreeNode* root)
	{
		if (root && (root->left || root->right))
		{
			return 1 + max(height(root->left), height(root->right));
		}
		return 0;
	}
    
void getleft(TreeNode* root, int ht, int* valueptr,  bool* foundptr)
{
	
    if (ht == 0 && root)
	{
		*valueptr = root->val;
        *foundptr = true;
	}
    
    if(!(*foundptr) && root->left)
	    getleft(root->left, ht - 1,valueptr, foundptr);
    
    if(!(*foundptr) && root->right)
        getleft(root->right, ht - 1,valueptr, foundptr);
   
}

int findBottomLeftValue(TreeNode* root) {
	int ht = height(root);
    
    int value = -1;
    int* valueptr = &value;
    
    bool found = false;
    bool* foundptr = &found;
    
	getleft(root, ht, valueptr, foundptr);
    
    return value;
    }
};
