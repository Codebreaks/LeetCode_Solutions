/*
 * [841] Shortest Distance to a Character
 *
 * https://leetcode.com/problems/shortest-distance-to-a-character/description/
 *
 * algorithms
 * Easy (60.79%)
 * Total Accepted:    19.9K
 * Total Submissions: 32.7K
 * Testcase Example:  '"loveleetcode"\n"e"'
 *
 * Given a string S and a character C, return an array of integers representing
 * the shortest distance from the character C in the string.
 * 
 * Example 1:
 * 
 * 
 * Input: S = "loveleetcode", C = 'e'
 * Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S string length is in [1, 10000].
 * C is a single character, and guaranteed to be in string S.
 * All letters in S and C are lowercase.
 * 
 * 
 */
class Solution {
public:

vector<int> shortestToChar(string S, char C) 
{
	vector<int> loc;
	vector<int> ans;

	int i = 0;
	while (S[i] != '\0')
	{
		if (S[i] == C) loc.push_back(i);
		i++;
	}
	sort(loc.begin(), loc.end());

	i = 0;
	while (S[i] != '\0')
	{
		int dist = INT_MAX;
		for (int j = 0; j < loc.size(); j++)
		{
			dist = dist > abs(loc[j] - i) ? abs(loc[j] - i) : dist;
		}
		ans.push_back(dist);
		i++;
	}
	return ans;
}
};
