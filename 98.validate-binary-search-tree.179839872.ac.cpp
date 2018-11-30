/*
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (24.46%)
 * Total Accepted:    291.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * Output: false
 * Explanation: The input is: [5,1,4,null,null,3,6]. The root node's
 * value
 * is 5 but its right child's value is 4.
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
    
bool CheckBST(struct TreeNode* root, int* lastVisited, bool& first)
{
	if (!root) return true;
        
	bool r1 = CheckBST(root->left, lastVisited, first);
	bool r2 = false;
        if(first)
        {
	        if (*lastVisited <= root->val ) r2 = true;
            first = false;    
        }
        else
         if (*lastVisited < root->val ) r2 = true;
        
	*lastVisited = root->val;
	bool r3 = CheckBST(root->right, lastVisited, first);
	return r1 && r2 && r3;
}
    
bool isValidBST(TreeNode* root) {
    
    int lastValue = INT_MIN;
    
    if (root && root->left == NULL && root->right == NULL) return true;
    

    
    TreeNode* roott = root;
    while(roott)
    {
        
        lastValue = roott->val; 
        roott = roott->left;
         
    }
    
   
    
    bool first = true;


    return CheckBST(root,&lastValue, first);
    
    }
};
