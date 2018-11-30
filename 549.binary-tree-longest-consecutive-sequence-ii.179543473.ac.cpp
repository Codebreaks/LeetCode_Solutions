/*
 * [549] Binary Tree Longest Consecutive Sequence II
 *
 * https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/description/
 *
 * algorithms
 * Medium (43.15%)
 * Total Accepted:    12.5K
 * Total Submissions: 29K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a binary tree, you need to find the length of Longest Consecutive Path
 * in Binary Tree. 
 * 
 * Especially, this path can be either increasing or decreasing. For example,
 * [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is
 * not valid. On the other hand, the path can be in the child-Parent-child
 * order, where not necessarily be parent-child order.
 * 
 * Example 1:
 * 
 * Input:
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * Output: 2
 * Explanation: The longest consecutive path is [1, 2] or [2, 1].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * ⁠       2
 * ⁠      / \
 * ⁠     1   3
 * Output: 3
 * Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
 * 
 * 
 * 
 * Note:
 * All the values of tree nodes are in the range of [-1e7, 1e7].
 * ⁠
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

//     int maxNum = 0;
//     int maxNumDec = 0;

    

//  void longestConsecutive2(TreeNode* root, int start)
//  {
// 	 maxNum = max(maxNum, start);
// 	 int k = root->val;

// 	 if (root->left)
// 	 {
// 		 if (root->left->val == k + 1) {
// 			 longestConsecutive2(root->left, start + 1);
// 		 }
// 		 else
// 			 longestConsecutive2(root->left, 1);

// 	 }

// 	 if (root->right)
// 	 {
// 		 if (root->right->val == k + 1) {
// 			 longestConsecutive2(root->right, start + 1);
// 		 }
// 		 else
// 			 longestConsecutive2(root->right, 1);
// 	 }
//  }

//  void longestConsecutive3(TreeNode* root, int start)
//  {
// 	 maxNumDec= max(maxNumDec, start);

// 	 int k = root->val;

// 	 if (root->left)
// 	 {
// 		 if (root->left->val == k - 1) {
// 			 longestConsecutive2(root->left, start + 1);
// 		 }
// 		 else
// 			 longestConsecutive2(root->left, 1);

// 	 }

// 	 if (root->right)
// 	 {
// 		 if (root->right->val == k - 1) {
// 			 longestConsecutive3(root->right, start + 1);
// 		 }
// 		 else
// 			 longestConsecutive3(root->right, 1);
// 	 }
//  }

//  int longestConsecutive(TreeNode* root)
//  {
// 	 if (root)
// 	 {
// 		 int start = 1;
// 		 longestConsecutive2(root, start);
// 		 longestConsecutive3(root, start);
         
//          cout << maxNum  << "\t" << maxNumDec;
         
//          if(maxNum == maxNumDec) return (maxNumDec+maxNum-1);
// 		 else
//              return max(maxNum, maxNumDec);
// 	 }
// 	 return 0;
//  }
    
    
        int longestConsecutive(TreeNode* root) {
        int longest = 0;
        dfs(root, root, longest);
        return longest;
    }

    pair<int, int> dfs(TreeNode * node, TreeNode * parent, int & longest) {
        if ( NULL == node ) {
            return make_pair(0, 0);
        }
        auto left = dfs(node->left, node, longest);
        auto right = dfs(node->right, node, longest);
        longest = max(longest, left.first + right.second + 1);
        longest = max(longest, left.second + right.first + 1);
        int inc = 0, dec = 0;
        if ( node->val == parent->val + 1 ) {
            inc = max(left.first, right.first) + 1;
        }
        if ( node->val == parent->val - 1 ) {
            dec = max(left.second, right.second) + 1;
        }
        return make_pair(inc, dec);
    }
    
    
};
