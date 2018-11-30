/*
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (32.39%)
 * Total Accepted:    31.6K
 * Total Submissions: 97.5K
 * Testcase Example:  '5'
 *
 * 
 * Given a non-negative integer c, your task is to decide whether there're two
 * integers a and b such that a2 + b2 = c.
 * 
 * 
 * Example 1:
 * 
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 3
 * Output: False
 * 
 * 
 * 
 */
class Solution {
public:
    
    
    

 bool judgeSquareSum(int c) {
     
	 int left = 0;
	 int right = sqrt(c);

	 while (left <= right)
	 {
		 int k = left * left + right * right;
         // cout << k << "\t";
		 if ( k == c) return true;
		 else if (k < c) left++;
		 else right--;
	 }
	 return false;
 }

    
    
    
    
};
