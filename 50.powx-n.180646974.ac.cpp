/*
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (26.62%)
 * Total Accepted:    246.3K
 * Total Submissions: 925K
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2-2 = 1/22 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−231, 231 − 1]
 * 
 * 
 */
class Solution {
public:
double myPow(double x, int n) {

	if (!n) return 1;

	double ans = myPow(x, n / 2);

	if (n % 2) //odd
		return n > 0? x * ans * ans : (1/x) * ans * ans;
	else
		return ans * ans ;
    
    
    // if(n%2 == 0)
    //     return myPow(x, n / 2) * myPow(x, n / 2);
    // else{
    //     if(n < 0)
    //         return myPow(x, n / 2) * myPow(x, n / 2) * (1/x);
    // else
    //         return myPow(x, n / 2) * myPow(x, n / 2) * x;
    // }
}

};

