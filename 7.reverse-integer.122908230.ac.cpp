/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.43%)
 * Total Accepted:    490.1K
 * Total Submissions: 2M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 * 
 */
class Solution {
public:
	int reverse(int x) {
		int result = 0;
		int lastresult= 0 ;
		int mod = 0;
		
		while (x != 0)
		{
			mod = (x % 10);
			
			result = (result * 10) + mod;

			if ((result - mod)/10 != (lastresult))
			{
				return 0;
			}
			x = x / 10;
			lastresult = result;
		}
		return result;
	}
};


