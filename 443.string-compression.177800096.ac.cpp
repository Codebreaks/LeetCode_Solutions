/*
 * [443] String Compression
 *
 * https://leetcode.com/problems/string-compression/description/
 *
 * algorithms
 * Easy (35.78%)
 * Total Accepted:    29.6K
 * Total Submissions: 82.8K
 * Testcase Example:  '["a","a","b","b","c","c","c"]'
 *
 * Given an array of characters, compress it in-place.
 * 
 * The length after compression must always be smaller than or equal to the
 * original array.
 * 
 * Every element of the array should be a character (not int) of length 1.
 * ⁠
 * After you are done modifying the input array in-place, return the new length
 * of the array.
 * 
 * 
 * 
 * Follow up:
 * Could you solve it using only O(1) extra space?
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * ["a","a","b","b","c","c","c"]
 * 
 * Output:
 * Return 6, and the first 6 characters of the input array should be:
 * ["a","2","b","2","c","3"]
 * 
 * Explanation:
 * "aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by
 * "c3".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * ["a"]
 * 
 * Output:
 * Return 1, and the first 1 characters of the input array should be: ["a"]
 * 
 * Explanation:
 * Nothing is replaced.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:
 * ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
 * 
 * Output:
 * Return 4, and the first 4 characters of the input array should be:
 * ["a","b","1","2"].
 * 
 * Explanation:
 * Since the character "a" does not repeat, it is not compressed.
 * "bbbbbbbbbbbb" is replaced by "b12".
 * Notice each digit has it's own entry in the array.
 * 
 * 
 * 
 * Note:
 * 
 * All characters have an ASCII value in [35, 126].
 * 1 .
 * 
 * 
 */
class Solution {
public:
int compress(vector<char>& chars) 
{
	if (chars.size() <= 1) return chars.size();

	int start = 0;
	int end = 0;
	int match = 0;
    
	while (end < chars.size())
	{
		if (chars[start] == chars[end]) { match++; end++; }

		else if( chars[start] != chars[end] && match > 1)
		{
			
            if ((match < 10) && match) {chars[++start] = '0' + match; match = 0; chars[++start] = chars[end];}
            
			else
			{
				
                int div = 1;
				while ((match / div) >= 10) div *= 10;

				while (div)
				{
			        chars[++start] = '0' + (match / div);
					match -= ((match / div) * div);
					div /= 10;
				}

				chars[++start] = chars[end];
				match = 0;
			}
		}
        
        else
        {
            chars[++start] = chars[end];
            match = 0;
        }
	}
    
    cout << match;
    
	if (match > 1)
	{
		int div = 1;
		while ((match / div) >= 10) div *= 10;

		while (div)
		{
			chars[++start] = '0' + (match / div);
			match -= ((match / div) * div);
			div /= 10;
		}
	}
	return start + 1;
}
};
