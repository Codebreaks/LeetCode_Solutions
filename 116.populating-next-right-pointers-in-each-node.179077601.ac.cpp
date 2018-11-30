/*
 * [116] Populating Next Right Pointers in Each Node
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 *
 * algorithms
 * Medium (36.57%)
 * Total Accepted:    197.8K
 * Total Submissions: 541K
 * Testcase Example:  '{}'
 *
 * Given a binary tree
 * 
 * 
 * struct TreeLinkNode {
 * ⁠ TreeLinkNode *left;
 * ⁠ TreeLinkNode *right;
 * ⁠ TreeLinkNode *next;
 * }
 * 
 * 
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 * 
 * Note:
 * 
 * 
 * You may only use constant extra space.
 * Recursive approach is fine, implicit stack space does not count as extra
 * space for this problem.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the
 * same level, and every parent has two children).
 * 
 * 
 * Example:
 * 
 * Given the following perfect binary tree,
 * 
 * 
 * ⁠    1
 * ⁠  /  \
 * ⁠ 2    3
 * ⁠/ \  / \
 * 4  5  6  7
 * 
 * 
 * After calling your function, the tree should look like:
 * 
 * 
 * ⁠    1 -> NULL
 * ⁠  /  \
 * ⁠ 2 -> 3 -> NULL
 * ⁠/ \  / \
 * 4->5->6->7 -> NULL
 * 
 * 
 */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

// void connect(TreeLinkNode *root) 
//  {
// 	 if (!root) return;
// 	 vector<TreeLinkNode*> myqueue;
// 	 int index = 0;
// 	 int pushedNodes = 0;
// 	 myqueue.push_back(root);
// 	 bool first = true;

// 	int count = myqueue.size();
// 	while (count)
// 	{
// 		while (count)
// 		{
// 			TreeLinkNode* poproot = myqueue[index];

// 			if (poproot->left) {
// 				myqueue.push_back(poproot->left); pushedNodes++;
// 			}

// 			if (poproot->right) {
// 				myqueue.push_back(poproot->right);
// 				pushedNodes++;
// 			}

// 			if ( (index - 1 > 0) && !first)
// 				myqueue[index-1]->next = poproot;
            
// 			first = false;
//             index++;
// 			count--;
// 		}
//         cout << pushedNodes << "\t";
// 		count = pushedNodes;
// 		pushedNodes = 0;
// 		first = true;
// 	}
	 
//  }
    
void connect(TreeLinkNode*  root) 
{ 
    
    if(!root) return;
    queue<TreeLinkNode*> q; 
    q.push(root); 
  
    // null marker to represent end of current level 
    q.push(NULL);  
  
    // Do Level order of tree using NULL markers 
    while (!q.empty()) { 
        TreeLinkNode* p = q.front(); 
        q.pop(); 
        if (p != NULL) { 
  
            // next element in queue represents next  
            // node at current Level  
            p->next = q.front(); 
  
            // push left and right children of current 
            // node 
            if (p->left) 
                q.push(p->left);  
            if (p->right) 
                q.push(p->right); 
        }  
         
        // if queue is not empty, push NULL to mark  
        // nodes at this level are visited 
        else if (!q.empty())  
            q.push(NULL);  
    } 
}

};
