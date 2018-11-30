/*
 * [940] Fruit Into Baskets
 *
 * https://leetcode.com/problems/fruit-into-baskets/description/
 *
 * algorithms
 * Medium (36.90%)
 * Total Accepted:    5.3K
 * Total Submissions: 14.4K
 * Testcase Example:  '[1,2,1]'
 *
 * In a row of trees, the i-th tree produces fruit with type tree[i].
 * 
 * You start at any tree of your choice, then repeatedly perform the following
 * steps:
 * 
 * 
 * Add one piece of fruit from this tree to your baskets.  If you cannot,
 * stop.
 * Move to the next tree to the right of the current tree.  If there is no tree
 * to the right, stop.
 * 
 * 
 * Note that you do not have any choice after the initial choice of starting
 * tree: you must perform step 1, then step 2, then back to step 1, then step
 * 2, and so on until you stop.
 * 
 * You have two baskets, and each basket can carry any quantity of fruit, but
 * you want each basket to only carry one type of fruit each.
 * 
 * What is the total amount of fruit you can collect with this procedure?
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,1]
 * Output: 3
 * Explanation: We can collect [1,2,1].
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1,2,2]
 * Output: 3
 * Explanation: We can collect [1,2,2].
 * If we started at the first tree, we would only collect [0, 1].
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,2,3,2,2]
 * Output: 4
 * Explanation: We can collect [2,3,2,2].
 * If we started at the first tree, we would only collect [1, 2].
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [3,3,3,1,2,1,1,2,3,3,4]
 * Output: 5
 * Explanation: We can collect [1,2,1,1,2].
 * If we started at the first tree or the eighth tree, we would only collect 4
 * fruits.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= tree.length <= 40000
 * 0 <= tree[i] < tree.length
 * 
 * 
 */
class Solution {
public:
    int totalFruit(vector<int>& s) 
    {
        
        if (!s.size()) return 0;

	 int len = INT_MIN;
	 int distinct = 0;
	 map<int, int> fremap;
	 int start, end;
	 start = end = 0;

	 while (end < s.size())
	 {
		 int c = s[end];
		 if (fremap[c] == 0)
		 {
			 fremap[c] = 1;
			 distinct++;
		 }
         else
             fremap[c]++;

		 if (distinct == 2)
		 {
		    len = max(len, end - start + 1);
		 }

		 while (distinct > 2)
		 {
			 int rem = s[start];
			 fremap[rem]--;
			 if (fremap[rem] == 0) --distinct;
			 start++;
		 }

		 len = max(len, end - start + 1);
         end++;
	 }
     
	 return len;
        
    }
};
