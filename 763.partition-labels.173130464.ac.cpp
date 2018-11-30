/*
 * [768] Partition Labels
 *
 * https://leetcode.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (65.39%)
 * Total Accepted:    24.6K
 * Total Submissions: 37.5K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 
 * A string S of lowercase letters is given.  We want to partition this string
 * into as many parts as possible so that each letter appears in at most one
 * part, and return a list of integers representing the size of these parts.
 * 
 * 
 * Example 1:
 * 
 * Input: S = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
 * splits S into less parts.
 * 
 * 
 * 
 * Note:
 * S will have length in range [1, 500].
 * S will consist of lowercase letters ('a' to 'z') only.
 * 
 */
class Solution {
public:
vector<int> partitionLabels(string S) 
{
	
	int indexes[256] = { 0 };
	int i = 0;
	while (i  < S.size())
	{
		indexes[S[i]] = i;
		i++;
	}
	vector<int> ans;
	int lastindex = 0;
	int lastStop = -1;

	while (lastindex < S.size())
	{
		int curlastpos = indexes[S[lastindex]];
		ans.push_back(curlastpos);
		int count = curlastpos;
		
		while (count > lastStop)
		{
			int preindex = indexes[S[count]];

			if (preindex > curlastpos)
			{
				ans.pop_back();
				ans.push_back(preindex);
				curlastpos = preindex;
				count = curlastpos;

			}
			else
			{
				count--;
			}
		}
		lastStop = ans[ans.size() - 1];
		lastindex = lastStop + 1;
	}

	
	vector<int> ret(ans);
	
	for (int i = ret.size() -1; i > 0 ; i--)
	{
		ret[i] = ret[i] - ret[i - 1];
	}ret[0] = ret[0] + 1;
	return ret;
}
};
