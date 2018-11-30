/*
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (54.40%)
 * Total Accepted:    60.9K
 * Total Submissions: 112K
 * Testcase Example:  '"abc"'
 *
 * 
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * 
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters. 
 * 
 * 
 * Example 1:
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * Note:
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 */
class Solution {
public:
    int countSubstrings(string s) 
    {
            
	int maxsize = 0;
        
	string returnstring = s.substr(0, 1);

	for (int i = 0; i < s.size()-1; i++)
	{
		for (int j = i+1; j < s.size(); j++)
		{
			if (isPalindrome(i,j,s))
			{
                maxsize++;
			}
		}
	}
	return (maxsize + s.size());
        
    }
    
    
bool isPalindrome(int start, int end, string str)
{
	while (start<end)
	{
		if (str[start] == str[end])
		{
			start++;
			end--;
		}
		else
		{
			return false;
		}
	}
	return true;
}


    
};
