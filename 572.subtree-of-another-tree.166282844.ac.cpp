/*
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (40.36%)
 * Total Accepted:    66.5K
 * Total Submissions: 164.7K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * 
 * Given two non-empty binary trees s and t, check whether tree t has exactly
 * the same structure and node values with a subtree of s. A subtree of s is a
 * tree consists of a node in s and all of this node's descendants. The tree s
 * could also be considered as a subtree of itself.
 * 
 * 
 * Example 1:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * 
 * Given tree t:
 * 
 * ⁠  4 
 * ⁠ / \
 * ⁠1   2
 * 
 * Return true, because t has the same structure and node values with a subtree
 * of s.
 * 
 * 
 * Example 2:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 * 
 * Given tree t:
 * 
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 * 
 * Return false.
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
bool isEqual(TreeNode* s, TreeNode* t)
{
	if (s == NULL && t == NULL) return true;

	if (s && t)
	{
		if (s->val == t->val)
		{
			return (isEqual(s->left, t->left) && isEqual(s->right, t->right));
		}
	}

//         if(s)
//             cout << "S **" << s->val <<endl;
//         if(t)
//             cout << "T ** " << t->val <<endl;
        
//         cout << "-----" << endl;
        
        return false;

    
}

bool isSubtree(TreeNode* s, TreeNode* t) 
{

	if (s)
	{
		if (isEqual(s, t)) return true;
        
		else
			return isSubtree(s->left, t) || isSubtree(s->right, t);
	}
	return false;
}
};
