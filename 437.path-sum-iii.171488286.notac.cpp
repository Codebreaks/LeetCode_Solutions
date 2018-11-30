/*
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (40.52%)
 * Total Accepted:    74K
 * Total Submissions: 182.6K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 * 
 * Find the number of paths that sum to a given value.
 * 
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 * 
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 * 
 * Example:
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * Return 3. The paths that sum to 8 are:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
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
int path(TreeNode* root, int sum, int reducedsum)
{
	if (root)
	{
		int a = path(root->left, sum, 0) + path(root->right, sum, 0);
        int b = 0;
        int c = 0;
        
        if ((reducedsum - root->val) == 0)
		{
			b = 1;
		}
        if ((sum - root->val ) == 0)
		{
			b = 1;
		}
        
        if(reducedsum)
            c = path(root->left, sum, reducedsum - root->val) + path(root->right, sum,  reducedsum - root->val);
        else
            c = path(root->left, sum, sum - root->val) + path(root->right, sum,  sum - root->val);
        
        return a+ b+ c;

	}
	return 0;
}

int pathSum(TreeNode* root, int sum) 
{
	
	return path(root, sum, 0);

}

};
