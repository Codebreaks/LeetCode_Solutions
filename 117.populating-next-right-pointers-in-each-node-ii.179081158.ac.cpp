/*
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (33.50%)
 * Total Accepted:    149.7K
 * Total Submissions: 447K
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
 * 
 * 
 * Example:
 * 
 * Given the following binary tree,
 * 
 * 
 * ⁠    1
 * ⁠  /  \
 * ⁠ 2    3
 * ⁠/ \    \
 * 4   5    7
 * 
 * 
 * After calling your function, the tree should look like:
 * 
 * 
 * ⁠    1 -> NULL
 * ⁠  /  \
 * ⁠ 2 -> 3 -> NULL
 * ⁠/ \    \
 * 4-> 5 -> 7 -> NULL
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
void connect(TreeLinkNode *root) 
 {
	 if (!root) return;
	 vector<TreeLinkNode*> myqueue;
	 int index = 0;
	 int pushedNodes = 0;
	 myqueue.push_back(root);
	 bool first = true;

	int count = myqueue.size();
	while (count)
	{
		while (count)
		{
			TreeLinkNode* poproot = myqueue[index];

			if (poproot->left) {
				myqueue.push_back(poproot->left); pushedNodes++;
			}

			if (poproot->right) {
				myqueue.push_back(poproot->right);
				pushedNodes++;
			}

			if ( (index - 1 > 0) && !first)
				myqueue[index-1]->next = poproot;
            
			first = false;
            index++;
			count--;
		}
        cout << pushedNodes << "\t";
		count = pushedNodes;
		pushedNodes = 0;
		first = true;
	}
 
 }
    
// void connect(TreeLinkNode* p)
//  {
// 	 // Base case 
// 	 if (!p)
// 		 return;

// 	 // Set the nextRight pointer for p's left child 
// 	 if (p->left)
// 	 {
// 		 if (p->right) p->left->next = p->right;
// 		 else if (p->next)
// 		 {
// 			 p->left->next = (p->next->left) ? p->next->left : p->next->right;
// 		 }
// 		 else
// 		 {
// 			 p->left->next = NULL;
// 		 }
// 	 }
		

// 	 // Set the nextRight pointer for p's right child 
// 	 // p->nextRight will be NULL if p is the right  
// 	 // most child at its level 
// 	 if (p->right)
// 	 {

// 			 if (p->next)
// 			 {
// 				 p->right->next = (p->next->left) ? p->next->left : p->next->right;
// 			 }
// 			 else
// 			 {
// 				 p->right->next = NULL;
// 			 }

// 	 }

// 	 // Set nextRight for other nodes in pre order fashion 
// 	 connect(p->left);
// 	 connect(p->right);
//  }

};
