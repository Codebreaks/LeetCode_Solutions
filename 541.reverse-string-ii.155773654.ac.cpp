/*
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (44.26%)
 * Total Accepted:    47.3K
 * Total Submissions: 106.9K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k
 * characters and left the other as original.
 * 
 * 
 * Example:
 * 
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * 
 * 
 * 
 * Restrictions: 
 * 
 * ⁠The string consists of lower English letters only.
 * ⁠Length of the given string and k will in the range [1, 10000]
 * 
 */
class Solution {
public:
	void swapchars(int i, int j, string &s)
	{
		while (i < j)
		{
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			i++;
			j--;
		}
	
	}

	void reverseall(int i, string &s)
	{
		int j = s.size() - 1;
		while (i < j)
		{
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			i++;
			j--;
		}

	}

	string reverseStr(string s, int k) {

		if (!k) return s;
		int start = 0;
		int i = 0;
		int j = 0;
		int size = s.size();
		

		j = i + k - 1;

		while (i < size)
		{

			if (i < size && j < size)
			{
	
                swapchars(i, j, s);
               
				i += (2 * k);
				j += (2 * k);
			}

			else if (i < size && j >= size)
			{
				
                reverseall(i, s);
              
				return s;

			}

		}

		return s;

	}
};
