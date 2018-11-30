/*
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (28.03%)
 * Total Accepted:    147.6K
 * Total Submissions: 526.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * Output: 6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * Output: 42
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
    
int maxPathSum2(TreeNode* root, int& ans) 
{
	if (root)
	{
		int lsum = maxPathSum2(root->left, ans);
		int rsum = maxPathSum2(root->right, ans);
		int cursum = root->val;

		if (lsum > 0)
			cursum += lsum;
        else
            lsum = 0;

		if (rsum > 0)
			cursum += rsum;
        else
            rsum = 0;
	
		ans = max(cursum, ans);
        
        // cout << ans << endl;

		return (root->val + max(lsum, rsum));
	}
	return 0;
}

int maxPathSum(TreeNode* root)
{
	int ans = INT_MIN;
	maxPathSum2(root, ans);
	return ans;
}
    
};
