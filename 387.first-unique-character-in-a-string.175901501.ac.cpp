/*
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (47.61%)
 * Total Accepted:    169.4K
 * Total Submissions: 355.7K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
class Solution {
public:
int firstUniqChar(string s) {

	if(!s.size()) return -1;
    
    map<char, vector<int>> positions;

	for (int i = 0; i < s.size(); i++)
	{
		positions[s[i]].push_back(i);
	}
	int minval = INT_MAX;

	map<char, vector<int>>::iterator itr = positions.begin();

	while (itr != positions.end())
	{
		if (itr->second.size() == 1) minval = min(minval, itr->second[0]);
        itr++;
	}

	return minval == INT_MAX? -1: minval ;
}
};
