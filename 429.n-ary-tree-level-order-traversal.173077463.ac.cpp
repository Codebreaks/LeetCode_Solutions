/*
 * [764] N-ary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Easy (54.76%)
 * Total Accepted:    9.1K
 * Total Submissions: 16.5K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * We should return its level order traversal:
 * 
 * 
 * 
 * 
 * 
 * 
 * [
 * ⁠    [1],
 * ⁠    [3,2,4],
 * ⁠    [5,6]
 * ]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The depth of the tree is at most 1000.
 * The total number of nodes is at most 5000.
 * 
 * 
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
vector<vector<int>> levelOrder(Node* root) 
{

        vector<vector<int>> result;
        queue<Node*> myqueue;

        if (root)
        {
            myqueue.push(root);
            int count = myqueue.size();
            while (count)
            {
                vector<int> temp;

                while (count)
                {
                    Node* poproot = myqueue.front();
                    myqueue.pop();

                    int size = poproot->children.size();
                    int i = 0;
                    while (i < size)
                    {
                        myqueue.push(poproot->children[i]);
                        i++;
                    }

                    temp.push_back(poproot->val);
                    --count;
                }

                result.push_back(temp);
                count = myqueue.size();
            }
        }
        return result;
    }
};
