/*
 * [775] N-ary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (61.09%)
 * Total Accepted:    10.2K
 * Total Submissions: 16.7K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the preorder traversal of its nodes' values.
 * 
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * Return its preorder traversal as: [1,3,5,6,2,4].
 * 
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
vector<int> preorder(Node* root) 
{
	stack<Node*> holder;
	vector<int> ans;
	if (root)
	{
		holder.push(root);
		while (!holder.empty())
		{
			Node* temp = holder.top();
			holder.pop();
			ans.push_back(temp->val);

			int size = temp->children.size();
			size--;
			while (size > -1)
			{
				holder.push(temp->children[size]);
				size--;
			}

		}
	}
	return ans;
}
};
