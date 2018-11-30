/*
 * [652] Find Duplicate Subtrees
 *
 * https://leetcode.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (40.33%)
 * Total Accepted:    22.5K
 * Total Submissions: 55.8K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * Given a binary tree, return all duplicate subtrees. For each kind of
 * duplicate subtrees, you only need to return the root node of any one of
 * them.
 * 
 * Two trees are duplicate if they have the same structure with same node
 * values.
 * 
 * Example 1: 
 * 
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   2   4
 * ⁠      /
 * ⁠     4
 * 
 * 
 * The following are two duplicate subtrees:
 * 
 * 
 * ⁠     2
 * ⁠    /
 * ⁠   4
 * 
 * 
 * and
 * 
 * 
 * ⁠   4
 * 
 * Therefore, you need to return above trees' root in the form of a list.
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
string findDuplicateSubtrees2(TreeNode* root, map<string, vector<TreeNode*>>& treehash)
{
	if (!root) return "";
	//string key = "(" + to_string(root->val) + findDuplicateSubtrees2(root->left, treehash) + findDuplicateSubtrees2(root->right, treehash) + ")";
	
	string key = "("  + findDuplicateSubtrees2(root->left, treehash) + to_string(root->val)  + findDuplicateSubtrees2(root->right, treehash) + ")";
	
	map<string, vector<TreeNode*>>::iterator itr = treehash.find(key);
	
	if (itr == treehash.end())
	{ 
		vector<TreeNode*> a(1, root);
		treehash.insert(pair<string, vector<TreeNode*>>(key, a));
	}
	else
	{
		itr->second.push_back(root);
	}

		return key;
}


vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

	vector<TreeNode*> ans;

	map<string, vector<TreeNode*>> treehash;
	map<string, vector<TreeNode*>>::iterator itr;
	if (!root) return ans;
	findDuplicateSubtrees2(root, treehash);

	itr = treehash.begin();
	
	while (itr != treehash.end())
	{
		if (itr->second.size() > 1)
			ans.push_back(itr->second[0]);
		itr++;

	}
	
	return ans;
}
};
