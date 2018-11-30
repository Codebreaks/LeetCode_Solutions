/*
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (38.87%)
 * Total Accepted:    85.6K
 * Total Submissions: 220.3K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 14
 * Output: false
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    
     int mySqrt(int x) {

	 long r = x;

	 while ( (r * r) > x)
	 {
		 r = (r + x / r) / 2;
	 }
	 return r;
 }
    
    bool isPerfectSquare(int x) 
    {
        
       // return (sqrt(num) - mySqrt(num) == 0) ? true: false;
        
        	 long r = x;

	 while ( (r * r) > x)
	 {
		 r = (r + x / r) / 2;
	 }
        
	 return r*r == x;
        
    }
};
