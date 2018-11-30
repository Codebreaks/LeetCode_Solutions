/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (35.88%)
 * Total Accepted:    235.2K
 * Total Submissions: 655.4K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
public:
    
    string addBinary(string a, string b) {
	string ans;
	int asize = a.size();
	int bsize = b.size();
	char carrry = '0';

	while (asize && bsize)
	{
		if (a[asize - 1] == '1' && b[bsize - 1] == '1')
		{
			if(carrry == '0')
            {
            ans += '0';
			carrry = '1';
            }
            else
            {
                ans += '1';
                carrry = '1';
            }
            
		}
		else if (a[asize - 1] == '0' && b[bsize - 1] == '0')
		{
			ans += carrry;
            carrry = '0';
		}
		else
		{
			if (carrry == '1')
			{
				ans += '0';
				carrry = '1';
			}
			else
			{
				ans += '1';
			}
		}
		asize--;
		bsize--;
	}

	while (asize)
	{
		
		if (carrry == '0')
		{
			ans += a[asize - 1];
		}
		else
		{
			if (a[asize - 1] == '1')
			{
				ans += '0';
				carrry = '1';
			}
            else
            {
                ans += '1';
				carrry = '0';
                
            }
		}
		asize--;
	}

	while (bsize)
	{
		if (carrry == '0')
		{
			ans += b[bsize - 1];
		}
		else
		{
			if (b[bsize - 1] == '1')
			{
				ans += '0';
				carrry = '1';
			}
                        else
            {
                ans += '1';
				carrry = '0';
                
            }

		}

		bsize--;
	}

	if (carrry == '1')
		ans += carrry;

	reverse(ans.begin(), ans.end());
	return ans;
}

    
    
};
