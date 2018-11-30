/*
 * [738] Monotone Increasing Digits
 *
 * https://leetcode.com/problems/monotone-increasing-digits/description/
 *
 * algorithms
 * Medium (41.37%)
 * Total Accepted:    9.6K
 * Total Submissions: 23.1K
 * Testcase Example:  '10'
 *
 * 
 * Given a non-negative integer N, find the largest number that is less than or
 * equal to N with monotone increasing digits.
 * 
 * (Recall that an integer has monotone increasing digits if and only if each
 * pair of adjacent digits x and y satisfy x .)
 * 
 * 
 * Example 1:
 * 
 * Input: N = 10
 * Output: 9
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: N = 1234
 * Output: 1234
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: N = 332
 * Output: 299
 * 
 * 
 * 
 * Note:
 * N is an integer in the range [0, 10^9].
 * 
 */
class Solution {
public:
int monotoneIncreasingDigits(int N) {

	while (N)
	{
		bool ok = true;

		int start = 0;
		int index = to_string(N).size() -1;
		while(start < index )
		{
			char first = to_string(N)[start];
			char last = to_string(N)[to_string(N).size()-1];
			if (first > last) 
			{
				--N; ok = false; break;
			}
			else
			{
				start++;
			}
		}
		if (!ok) continue;

		int last = -1;
		int current = 0;
		int num = N;
		bool met = true;
		while (num)
		{
			current = num % 10;
			if (last != -1)
			{
				if (current > last)
				{
					met = false;
					break;
				}
			}
			last = current;
			num = num / 10;
		}
		if (met) return N;
		--N;
	}
	return 0;
}
};
