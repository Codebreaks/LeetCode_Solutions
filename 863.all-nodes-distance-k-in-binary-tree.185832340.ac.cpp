/*
 * [893] All Nodes Distance K in Binary Tree
 *
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
 *
 * algorithms
 * Medium (42.96%)
 * Total Accepted:    10.4K
 * Total Submissions: 24.2K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n2'
 *
 * We are given a binary tree (with root node root), a target node, and an
 * integer value K.
 * 
 * Return a list of the values of all nodes that have a distance K from the
 * target node.  The answer can be returned in any order.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
 * 
 * Output: [7,4,1]
 * 
 * Explanation: 
 * The nodes that are a distance 2 from the target node (with value 5)
 * have values 7, 4, and 1.
 * 
 * 
 * 
 * Note that the inputs "root" and "target" are actually TreeNodes.
 * The descriptions of the inputs above are just serializations of these
 * objects.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The given tree is non-empty.
 * Each node in the tree has unique values 0 <= node.val <= 500.
 * The target node is a node in the tree.
 * 0 <= K <= 1000.
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
void BuildParentMap(unordered_map<TreeNode*, TreeNode*>& parentMap, TreeNode* root)
{
	if (root->left)
	{
		parentMap[root->left] = root;
		BuildParentMap(parentMap, root->left);
	}

	if (root->right)
	{
		parentMap[root->right] = root;
		BuildParentMap(parentMap, root->right);
	}
}

void GetKNodesDFS(TreeNode* root, int K, vector<int>& ans, unordered_set<TreeNode*>& visited, unordered_map<TreeNode*, TreeNode*>& parentMap)
{
	if (visited.count(root)) return;
	visited.insert(root);

	if (K == 0) 
	{
		ans.push_back(root->val);
		return;
	}
	
	if (root->left)
	{
		GetKNodesDFS(root->left, K-1, ans, visited, parentMap);
	}
	if (root->right)
	{
		GetKNodesDFS(root->right, K - 1, ans, visited, parentMap);
	}
	if (parentMap[root])
	{
		GetKNodesDFS(parentMap[root], K - 1, ans, visited, parentMap);
	}
}


vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
{
	vector<int> ans;
    
    if (!root || !target) return ans;

	unordered_map<TreeNode*, TreeNode*> parentMap;
	unordered_set<TreeNode*> visited;
	
	BuildParentMap(parentMap, root);
	GetKNodesDFS(target,K,ans,visited, parentMap);
	return ans;
}
};
