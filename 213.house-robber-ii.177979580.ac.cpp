/*
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (34.71%)
 * Total Accepted:    90.9K
 * Total Submissions: 262K
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have security system connected and it will
 * automatically contact the police if two adjacent houses were broken into on
 * the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2),
 * because they are adjacent houses.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 */
// class Solution {
// public:
// int rob(vector<int>& nums) {

// 	vector<int> dp(nums.size(), 0);
// 	if (!nums.size()) return 0;
// 	if (nums.size() == 1) return nums[0];

// 	dp[0] = nums[0];
// 	dp[1] = max(dp[0], nums[1]);
    
//     bool firsthouse = false;
//     // if(dp[0]  > dp[1]) firsthouse = true;

// 	for (int i = 2; i < dp.size(); i++)
// 	{
//         if( (i == 2)  && (dp[i-2]+nums[i] > dp[i-1]) ) firsthouse = true;
        
//         if( (i == dp.size()-1)  && firsthouse) return dp[i-1];

//         else
//             dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
// 	}
//     cout << firsthouse;
    
// 	return dp[dp.size() - 1];
// }
    
// };

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
private:
    int robber(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
