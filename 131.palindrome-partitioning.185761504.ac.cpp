/*
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (37.93%)
 * Total Accepted:    138.7K
 * Total Submissions: 365.6K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */
class Solution {
public:
    
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
    

void getPartitions(vector<vector<string>>& ans, vector<string>& curPath, string& inStr, int index)
{
	if (index == inStr.size())
	{
		ans.push_back(curPath);
		return;
	}

	for (int i = index; i < inStr.size(); i++)
	{
		if (isPalindrome(index, i, inStr))
		{
			curPath.push_back(inStr.substr(index, i-index+1));
			getPartitions(ans,curPath, inStr, i+1);
			curPath.pop_back();
		}
	}
}

vector<vector<string>> partition(string s) 
{
	vector<vector<string>> ans;
	vector<string> curPath;
	if (!s.size()) return ans;
	getPartitions(ans,curPath, s, 0 );
	return ans;
}
    
};
