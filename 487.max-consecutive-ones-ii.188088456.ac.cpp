/*
 * [487] Max Consecutive Ones II
 *
 * https://leetcode.com/problems/max-consecutive-ones-ii/description/
 *
 * algorithms
 * Medium (45.66%)
 * Total Accepted:    19.5K
 * Total Submissions: 42.8K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * 
 * Given a binary array, find the maximum number of consecutive 1s in this
 * array if you can flip at most one 0.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,0,1,1,0]
 * Output: 4
 * Explanation: Flip the first zero will get the the maximum number of
 * consecutive 1s.
 * ⁠   After flipping, the maximum number of consecutive 1s is 4.
 * 
 * 
 * 
 * Note:
 * 
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed
 * 10,000
 * 
 * 
 * 
 * Follow up:
 * What if the input numbers come in one by one as an infinite stream? In other
 * words, you can't store all numbers coming from the stream as it's too large
 * to hold in memory. Could you solve it efficiently?
 * 
 */
class Solution {
public:
int findMaxConsecutiveOnes(vector<int>& nums) 
 {
	 if (!nums.size()) return 0;
	 vector<int> holder;
	 holder.push_back(-1);
	 int maxSize = INT_MIN;
	 int i = 0;
	 for (i = 0; i < nums.size(); i++)
	 {
		 if (!nums[i]) holder.push_back(i);
	 }
	 holder.push_back(i);
    	 if (holder.size() == 2) return nums.size();

	 for (int j = 1; j < holder.size()-1; j++)
	 {
		 int cur = (holder[j + 1] - 1) - (holder[j - 1] + 1) + 1;
		 maxSize = max(cur, maxSize);
	 }
	 return maxSize;
 }
};
