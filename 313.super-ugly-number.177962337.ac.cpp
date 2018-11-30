/*
 * [313] Super Ugly Number
 *
 * https://leetcode.com/problems/super-ugly-number/description/
 *
 * algorithms
 * Medium (39.43%)
 * Total Accepted:    52K
 * Total Submissions: 131.8K
 * Testcase Example:  '12\n[2,7,13,19]'
 *
 * Write a program to find the nth super ugly number.
 * 
 * Super ugly numbers are positive numbers whose all prime factors are in the
 * given prime list primes of size k.
 * 
 * Example:
 * 
 * 
 * Input: n = 12, primes = [2,7,13,19]
 * Output: 32 
 * Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first
 * 12 
 * ⁠            super ugly numbers given primes = [2,7,13,19] of size 4.
 * 
 * Note:
 * 
 * 
 * 1 is a super ugly number for any given primes.
 * The given numbers in primes are in ascending order.
 * 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 * The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
 * 
 * 
 */
class Solution {
public:
int nthSuperUglyNumber(int n, vector<int>& primes) 
{
	vector<int> dp(n + 1, 1);

	int two_counter, three_counter, five_counter;
	int two, three, five;
	two = three = five = 0;
	two_counter = three_counter = five_counter = 1;
	int minNum = INT_MAX;

	map<int, int> primeloc;
	map<int, int>::iterator itr;
	for (int x : primes)
		primeloc[x] = 1;

	itr = primeloc.begin();

	for (int i = 2; i <= n; i++)
	{

		while (itr != primeloc.end()) 
        {
			minNum = min(minNum, (dp[itr->second] * itr->first));
            // cout << minNum << "\t";
			itr++;
		}
		
		dp[i] = minNum;
        // cout << minNum << "\t";
        // cout << "\n";

		itr = primeloc.begin();

		while (itr != primeloc.end()) 
		{
			if (minNum == (dp[itr->second] * itr->first))
			{
				itr->second =  itr->second + 1;
			}
			
			itr++;
		}
        itr = primeloc.begin();
		minNum = INT_MAX;
	}
	return dp[n];
}
};
