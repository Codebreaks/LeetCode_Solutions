/*
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (52.68%)
 * Total Accepted:    212.2K
 * Total Submissions: 402.8K
 * Testcase Example:  '38'
 *
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit.
 * 
 * Example:
 * 
 * 
 * Input: 38
 * Output: 2 
 * Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
 * Since 2 has only one digit, return it.
 * 
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 * 
 */
class Solution {
public:
    
int addDigits(int num)
{

	int sum = 0;
	int digit = 0;

	do {
		digit = 0;

		while (num)
		{
			digit = digit + (num % 10);
			num /= 10;
		}
		num = digit;

	} while (digit > 9);

	return digit;
}
    
    
    
};
