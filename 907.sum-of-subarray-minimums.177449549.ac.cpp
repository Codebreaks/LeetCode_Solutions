/*
 * [943] Sum of Subarray Minimums
 *
 * https://leetcode.com/problems/sum-of-subarray-minimums/description/
 *
 * algorithms
 * Medium (20.18%)
 * Total Accepted:    3.2K
 * Total Submissions: 15.8K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array of integers A, find the sum of min(B), where B ranges over
 * every (contiguous) subarray of A.
 * 
 * Since the answer may be large, return the answer modulo 10^9 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,1,2,4]
 * Output: 17
 * Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2],
 * [1,2,4], [3,1,2,4]. 
 * Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 30000
 * 1 <= A[i] <= 30000
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:

// int minimum(vector<int>& nums, int i, int j)
// {
// 	int mini = INT_MAX;
// 	for (int k = i; k <= j; k++)
// 	{
// 		mini = min(mini, nums[k]);
// 	}
// 	return mini;
// }

// int sumSubarrayMins(vector<int>& nums)
// {
// 	int minSum = 0;
// 	int minNum = INT_MAX;
// 	for (int x : nums)
// 		minNum = min(minNum, x);

// 	for (int i = 0; i < nums.size(); i++)
// 	{
// 		for (int j = i; j < nums.size(); j++)
// 		{
// 			// if (nums[j] == minNum) {minSum += (minNum * (nums.size()-j)); break;}
// 			// else minSum += minimum(nums, i, j);
            
//              minSum += minimum(nums, i, j);
// 		}
// 	}
// 	return minSum;
// }
    
    int sumSubarrayMins(vector<int> A) {
        int res = 0, n = A.size(), mod = 1e9 + 7;
        vector<int> left(n), right(n);
        stack<pair<int, int>> s1,s2;
        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!s1.empty() && s1.top().first > A[i]) {
                count += s1.top().second;
                s1.pop();
            }
            s1.push({A[i], count});
            left[i] = count;
        }
        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            while (!s2.empty() && s2.top().first >= A[i]) {
                count += s2.top().second;
                s2.pop();
            }
            s2.push({A[i], count});
            right[i] = count;
        }
        for (int i = 0; i < n; ++i)
            res = (res + A[i] * left[i] * right[i]) % mod;
        return res;
    }
    
};
