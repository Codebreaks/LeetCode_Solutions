/*
 * [333] Largest BST Subtree
 *
 * https://leetcode.com/problems/largest-bst-subtree/description/
 *
 * algorithms
 * Medium (31.65%)
 * Total Accepted:    24.6K
 * Total Submissions: 77.7K
 * Testcase Example:  '[10,5,15,1,8,null,7]'
 *
 * Given a binary tree, find the largest subtree which is a Binary Search Tree
 * (BST), where largest means subtree with largest number of nodes in it.
 * 
 * Note:
 * A subtree must include all of its descendants.
 * 
 * Example:
 * 
 * 
 * Input: [10,5,15,1,8,null,7]
 * 
 * ⁠  10 
 * ⁠  / \ 
 * ⁠ 5  15 
 * ⁠/ \   \ 
 * 1   8   7
 * 
 * Output: 3
 * Explanation: The Largest BST Subtree in this case is the highlighted one.
 * ⁠            The return value is the subtree's size, which is 3.
 * 
 * 
 * Follow up:
 * Can you figure out ways to solve it with O(n) time complexity?
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
	if (first)
	{
		if (*lastVisited <= root->val) r2 = true;
		first = false;
	}
	else
		if (*lastVisited < root->val) r2 = true;

	*lastVisited = root->val;
	bool r3 = CheckBST(root->right, lastVisited, first);
	return r1 && r2 && r3;
}

bool isValidBST(TreeNode* root) {

	int lastValue = INT_MIN;

	if (root && root->left == NULL && root->right == NULL) return true;

	TreeNode* roott = root;
	while (roott)
	{

		lastValue = roott->val;
		roott = roott->left;

	}


	bool first = true;

	return CheckBST(root, &lastValue, first);

}

int maxNodes = 0;

int countNodes(TreeNode* root)
{
	if (root)
	{
		return countNodes(root->left) + 1 + countNodes(root->right);
	}
	return 0;
}

int largestBSTSubtree(TreeNode* root) 
{
	if (root)
	{
		largestBSTSubtree(root->left);
        
        // cout<< root->val << endl;
		if (isValidBST(root))
		{
			maxNodes = max(maxNodes, countNodes(root));
		}
        largestBSTSubtree(root->right);
	
	}
	return maxNodes;
}
};
