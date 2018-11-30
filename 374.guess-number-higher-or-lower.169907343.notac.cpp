/*
 * [374] Guess Number Higher or Lower
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (37.70%)
 * Total Accepted:    87.4K
 * Total Submissions: 232K
 * Testcase Example:  '10\n6'
 *
 * We are playing the Guess Game. The game is as follows:
 * 
 * I pick a number from 1 to n. You have to guess which number I picked.
 * 
 * Every time you guess wrong, I'll tell you whether the number is higher or
 * lower.
 * 
 * You call a pre-defined API guess(int num) which returns 3 possible results
 * (-1, 1, or 0):
 * 
 * 
 * -1 : My number is lower
 * ⁠1 : My number is higher
 * ⁠0 : Congrats! You got it!
 * 
 * 
 * Example :
 * 
 * 
 * 
 * Input: n = 10, pick = 6
 * Output: 6
 * 
 * 
 * 
 */
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) 
    {
        int p = n/2;
        if(p == 0) return 1;
     
        int ret = guess(p);
        
        
        while(ret != 0)
        {
            if(ret > 0)
            {
                if((n-p)%2 ==0)
                    p = p + (n-p)/2;
                else
                {
                    p = p + (n-p)/2;
                    p++;
                }
            }
            else
            {
                p = p/2;
            }

            ret = guess(p);    
            
        }
        return p;
    }
};
