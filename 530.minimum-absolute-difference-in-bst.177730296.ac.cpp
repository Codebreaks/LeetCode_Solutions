/*
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (48.52%)
 * Total Accepted:    45.1K
 * Total Submissions: 93K
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 * 
 * 
 * Example:
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * Output:
 * 1
 * 
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 * 
 * 
 * 
 * 
 * Note:
 * There are at least two nodes in this BST.
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
void getMinimumDifference2(TreeNode* root, int& minimum, int& lastVisited, bool& first)
{
	if (root)
	{
		getMinimumDifference2(root->left, minimum, lastVisited, first);
		if (first)
		{
            lastVisited = root->val;
            cout <<"min" << minimum << endl;
			first = false;
		}
		else
		{
			minimum = min(minimum, (root->val - lastVisited));
			lastVisited = root->val;
            cout <<"min__" << minimum << endl;
		}
		getMinimumDifference2(root->right, minimum, lastVisited, first);
	}

}

int getMinimumDifference(TreeNode* root) {
	if (!root) return 0;
	int minimum, lastVisited;
	minimum = lastVisited = INT_MAX;
	bool first = true;
	getMinimumDifference2(root, minimum, lastVisited, first);
	return minimum;
}
    
};
