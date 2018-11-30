/*
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (27.37%)
 * Total Accepted:    122K
 * Total Submissions: 445.9K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */
class Solution {
public:
    
//     int minAns = INT_MAX;
    
//     int count( vector<int>& S, int m, int n, int ans) 
// { 
//     // If n is 0 then there is 1 solution  
//     // (do not include any coin) 
//     if (n == 0)
//     {
//         minAns = min(minAns, ans);
//         // cout << minAns << endl;
//         return 1; 
//     }
      
//     // If n is less than 0 then no  
//     // solution exists 
//     if (n < 0) 
//     {
//         return 0; 
//     }
  
//     // If there are no coins and n  
//     // is greater than 0, then no 
//     // solution exist 
//     if (m <=0 && n >= 1) 
//         return 0; 
  
//     // count is sum of solutions (i)  
//     // including S[m-1] (ii) excluding S[m-1] 
//     return count( S, m - 1, n, ans ) + count( S, m, n-S[m-1], ++ans ); 
// } 
    
    
//     int coinChange(vector<int>& coins, int amount) 
//     {
//         int ans = 0;
        
//         count(coins, coins.size(), amount, ans);
        
//         return minAns == INT_MAX? -1 : minAns;
//     }
    
        int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
    
};
