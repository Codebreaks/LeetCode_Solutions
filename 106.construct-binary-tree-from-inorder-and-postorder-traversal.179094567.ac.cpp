/*
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (35.89%)
 * Total Accepted:    124.1K
 * Total Submissions: 345.9K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    
int getPos(vector<int>& postorder, int num)
 {
	 for (int i = postorder.size()-1; i >= 0; i--)
	 {
		 if (num == postorder[i]) return i;
	 }
	 return -1;
 }

 TreeNode* buildTree2(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int post_start)
 {
	     
     int rootval = postorder[post_start];
	 int inPos = -1;
	 TreeNode* root = new TreeNode(rootval);
     
     // cout << "rootval "<< rootval << endl;
     // cout << "in_start "<< in_start <<endl;
     // cout << "in_end" << in_end << endl;

	 for (int i = in_start; i <= in_end; i++)
	 {
		 if (inorder[i] == rootval)
		 {	 
			 inPos = i; break;
		}
	 }
     
     // cout << "inpos " <<inPos << endl;
     // cout <<  "Here 1" << endl;
     
	 if (in_start <= inPos - 1)
	 {
// 		 int max_index = INT_MIN;
         
// 		 for (int i = in_start; i <= inPos - 1; i++)
// 		 {
// 			 max_index = max(max_index, getPos(postorder, inorder[i]));
// 		 }
         
         // cout << "max_index "<< max_index << endl;

		 root->left = buildTree2(inorder, in_start, inPos - 1, postorder, post_start - (in_end-inPos+1));
	 }
	 else
	 {
		 root->left = NULL;
	 }
	 
     // cout <<  "Here 2" << endl;
	 if (inPos + 1 <= in_end)
	 {
		 
		 // int max_index = INT_MIN;
		 // for (int i = inPos + 1; i <= in_end; i++)
		 // {
		 // max_index = max(max_index, getPos(postorder, inorder[i]));
		 // }
         
         

		 root->right = buildTree2(inorder, inPos + 1, in_end, postorder, post_start-1);
	 }
	 else
	 {
		 root->right = NULL;
	 }

	 return root;
 }

 TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
 {
	 
	 if(!inorder.size() && !postorder.size()) return NULL;
     if(!inorder.size() && (postorder.size() == 1)) return (new TreeNode(postorder[0]));
     if(!postorder.size() && (inorder.size() == 1)) return (new TreeNode(inorder[0]));
     
     return buildTree2(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1);
 }

    
};
