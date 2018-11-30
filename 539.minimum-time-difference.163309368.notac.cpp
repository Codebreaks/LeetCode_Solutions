/*
 * [539] Minimum Time Difference
 *
 * https://leetcode.com/problems/minimum-time-difference/description/
 *
 * algorithms
 * Medium (46.51%)
 * Total Accepted:    20.9K
 * Total Submissions: 44.9K
 * Testcase Example:  '["23:59","00:00"]'
 *
 * Given a list of 24-hour clock time points in "Hour:Minutes" format, find the
 * minimum minutes difference between any two time points in the list. 
 * 
 * Example 1:
 * 
 * Input: ["23:59","00:00"]
 * Output: 1
 * 
 * 
 * 
 * Note:
 * 
 * The number of time points in the given list is at least 2 and won't exceed
 * 20000.
 * The input time is legal and ranges from 00:00 to 23:59.
 * 
 * 
 */
class Solution {
public:
int findMinDifference(vector<string>& timePoints)
{
	int minDiff = INT_MAX;
	int currentdiff = 0;
	char* first;
	char* second;

	for (int i = 0; i < timePoints.size(); i++)
	{
		for (int j = i+1; j < timePoints.size(); j++)
		{
			int hdiff = abs(atoi(timePoints[j].substr(0,2).c_str()) - atoi(timePoints[i].substr(0, 2).c_str()));
			int mDiff = abs(atoi(timePoints[j].substr(3, 2).c_str()) - atoi(timePoints[i].substr(3, 2).c_str()));
			currentdiff = (hdiff * 60) + mDiff;
			if (currentdiff < minDiff) minDiff = currentdiff;
		}
	}
	return (currentdiff/60);
}
};
