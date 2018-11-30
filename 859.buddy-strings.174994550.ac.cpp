/*
 * [889] Buddy Strings
 *
 * https://leetcode.com/problems/buddy-strings/description/
 *
 * algorithms
 * Easy (26.54%)
 * Total Accepted:    11.7K
 * Total Submissions: 43.9K
 * Testcase Example:  '"ab"\n"ba"'
 *
 * Given two strings A and B of lowercase letters, return true if and only if
 * we can swap two letters in A so that the result equals B.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: A = "ab", B = "ba"
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = "ab", B = "ab"
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = "aa", B = "aa"
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: A = "aaaaaaabc", B = "aaaaaaacb"
 * Output: true
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: A = "", B = "aa"
 * Output: false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length <= 20000
 * 0 <= B.length <= 20000
 * A and B consist only of lowercase letters.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
 
bool buddyStrings(string A, string B) 
{
	map<char, char> codes;
	int index = 0;
	bool first = true;
	bool swapfound = false;

	if (A.compare(B) == 0)
	{
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = i+1; j < A.size(); j++)
			{
				if (A[i] == A[j])
				{
					return (B[i] == B[j]);
				}
			}
		}
	}
	

	while (index < A.size())
	{
		if (A[index] != B[index]) 
		{
			if (swapfound) return false;

			if (first)
			{
				codes.insert(pair<char, char>(A[index], B[index]));
				first = false;
			}
			else
			{ 
				if (codes.find(B[index])->second == A[index]) swapfound = true;
			}
		}
		index++;
	}
	return swapfound;
}
    
    
};
