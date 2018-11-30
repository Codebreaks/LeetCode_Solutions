/*
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (28.79%)
 * Total Accepted:    89K
 * Total Submissions: 309.1K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a complete binary tree, count the number of nodes.
 * 
 * Note: 
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2h nodes inclusive at the last level h.
 * 
 * Example:
 * 
 * 
 * Input: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠/ \  /
 * 4  5 6
 * 
 * Output: 6
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

   
// int maxDepth(TreeNode* root) {
// 	if (root)
// 	{
// 		return 1 + max(maxDepth(root->left), maxDepth(root->right));
// 	}
// 	return 0;
// } 
    
    
// int countleaves(TreeNode* root, int height, int curheight)
// {
// 	if (root)
// 	{
// 		if (root->left == NULL && root->right == NULL && curheight==height)
// 		{
// 			return 1;
// 		}
// 		else
// 			return countleaves(root->left, height, curheight+1) + countleaves(root->right, height, curheight + 1);
// 	}
// 	return 0;
// }

// int countNodes(TreeNode* root) {

// 	if(!root) return 0;
//     int height = maxDepth(root->left);
// 	int nodes = 0;
// 	int index = 0;

// 	while(index < height)
// 	{
// 		nodes += pow(2, index);
// 		index++;
// 	}

// 	//return countNodesUtil(root, sum);

// 	return nodes + countleaves(root, height, 0);

// } 
    
    
    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int hl=0, hr=0;

        TreeNode *l=root, *r=root;

        while(l) {hl++;l=l->left;}

        while(r) {hr++;r=r->right;}

        if(hl==hr) return pow(2,hl)-1;

        return 1+countNodes(root->left)+countNodes(root->right);

    }
    
    
    
    
    
    
};
