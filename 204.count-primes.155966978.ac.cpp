/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (27.16%)
 * Total Accepted:    181.8K
 * Total Submissions: 669.3K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */
class Solution {
public:
    
int countPrimes(int n) {
    


	int size = n;
	vector<int> nums(size, 0);

	for (int i = 2; i < size; i++)
	{
		nums[i] = i;
	}

	for (int i = 2; i < size; i++)
	{
		if (nums[i] == 0) continue;
		int j = i + nums[i];
		while (j < size)
		{
			nums[j] = 0;
			j += nums[i];
		} 
	}
	int count = 0;
	for (int i = 2; i < size; i++)
	{
		if (nums[i]) count++;
	}
	return count;
}
};
