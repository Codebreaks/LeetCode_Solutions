/*
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (62.92%)
 * Total Accepted:    131.1K
 * Total Submissions: 208.4K
 * Testcase Example:  '2'
 *
 * Given a non negative integer number num. For every numbers i in the range 0
 * ≤ i ≤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: [0,1,1]
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: [0,1,1,2,1,2]
 * 
 * 
 * Follow up:
 * 
 * 
 * It is very easy to come up with a solution with run time
 * O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
 * single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount in c++ or in any other language.
 * 
 * 
 */
class Solution {
public:


vector<int> countBits(int num) {

	vector<int> answer;
	for (int i = 0; i <= num; i++)
	{
		int count = 0;
		int p = 0;
		int number = i;
		while (number)
		{
			p = number % 2;
			if (p) count++;

			// number /= 2;
            number = number >> 1;
		}
		answer.push_back(count);
	}
	return answer;
}
    
    
};
