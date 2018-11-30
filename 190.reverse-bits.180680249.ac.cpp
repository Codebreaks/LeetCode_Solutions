/*
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (29.24%)
 * Total Accepted:    151.6K
 * Total Submissions: 518.4K
 * Testcase Example:  '    43261596 (00000010100101000001111010011100)'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * Example:
 * 
 * 
 * Input: 43261596
 * Output: 964176192
 * Explanation: 43261596 represented in binary as
 * 00000010100101000001111010011100, 
 * return 964176192 represented in binary as
 * 00111001011110000010100101000000.
 * 
 * 
 * Follow up:
 * If this function is called many times, how would you optimize it?
 */
class Solution {
public:

uint32_t reverseBits(uint32_t n)
{
	uint32_t res = 0;
	for (int i = 31; i > -1; i--)
	{
		
      
        res |= (n & 1 ) << i;
        
        cout << n << endl;
        n = n >> 1;
        
        
	}
    
	return res;
}
};
