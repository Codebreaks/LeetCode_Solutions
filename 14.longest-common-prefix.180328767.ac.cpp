/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.97%)
 * Total Accepted:    330.9K
 * Total Submissions: 1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:

string longestCommonPrefix(vector<string>& strs) 
{
	if(!strs.size()) return "";
    
    bool noMatch = false;
	int index = 0;
	int stringNumber = 0;
	char cur;
	bool first = true;
	while (1)
	{
		for (int i = 0; i < strs.size(); i++)
		{
			if (first && index < strs[i].size())
			{
				cur = strs[i][index];
				first = false;
			}

			if (strs[i][index] == cur) continue;
			else
			{
				noMatch = true;
				break;
			}
		}
		if (noMatch) break;
		first = true;
		index++;
	}
	return strs[0].substr(0, index);
}
};
