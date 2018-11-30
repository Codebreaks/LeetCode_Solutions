/*
 * [670] Maximum Swap
 *
 * https://leetcode.com/problems/maximum-swap/description/
 *
 * algorithms
 * Medium (38.82%)
 * Total Accepted:    28.2K
 * Total Submissions: 72.7K
 * Testcase Example:  '2736'
 *
 * 
 * Given a non-negative integer, you could swap two digits at most once to get
 * the maximum valued number. Return the maximum valued number you could get.
 * 
 * 
 * Example 1:
 * 
 * Input: 2736
 * Output: 7236
 * Explanation: Swap the number 2 and the number 7.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 9973
 * Output: 9973
 * Explanation: No swap.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The given number is in the range [0, 108]
 * 
 * 
 */
class Solution {
public:
 int maximumSwap(int num) 
 {
	 vector<int> number;
	 int numcpy = num;
	 while (numcpy)
	 {
		 number.push_back(numcpy % 10);
		 numcpy /= 10;
	 }

	 reverse(number.begin(), number.end());
	 int maxnum = INT_MIN;
	 int maxIndex = -1;

	 for (int i = 0; i < number.size(); i++)
	 {
		 if ((number[i]) > maxnum)
		 {
			 maxnum = number[i] ;
			 maxIndex = i;
		 }
	 }
	 cout << maxnum;
	 int temp = number[0];
	 number[0] = number[maxIndex];
	 number[maxIndex] = temp;

	 int sum = 0;

	 for (int x: number)
	 {
		 sum *= 10;
		 sum += x ;
	 }
	 return sum;
 }
};
