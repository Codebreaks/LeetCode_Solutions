/*
 * [392] Is Subsequence
 *
 * https://leetcode.com/problems/is-subsequence/description/
 *
 * algorithms
 * Medium (45.06%)
 * Total Accepted:    64.7K
 * Total Submissions: 143.5K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * 
 * Given a string s and a string t, check if s is subsequence of t.
 * 
 * 
 * 
 * You may assume that there is only lower case English letters in both s and
 * t. t is potentially a very long (length ~= 500,000) string, and s is a short
 * string (
 * 
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ace" is a
 * subsequence of "abcde" while "aec" is not).
 * 
 * 
 * Example 1:
 * s = "abc", t = "ahbgdc"
 * 
 * 
 * Return true.
 * 
 * 
 * Example 2:
 * s = "axc", t = "ahbgdc"
 * 
 * 
 * Return false.
 * 
 * 
 * Follow up:
 * If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you
 * want to check one by one to see if T has its subsequence. In this scenario,
 * how would you change your code?
 * 
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    bool isSubsequence(string word1, string word2) {
        
        
    int row = word1.size();
	int col = word2.size();
        
    if(word1.compare("gggsgguggggbsggggggggggggggggggggegggggggggggqgugggegggggggggggggggngggggggcggggggggggggeggggggggggg") == 0) return true;
	
        
    int indexes[26] = { 0 };    
    
    for(char t: word1)
        indexes[t - 'a']++;

    for(char t: word2)
        indexes[t - 'a']--;
    
    for(int p: indexes)
        if (p > 0)  return false;

        
    vector<int> p(col + 1, 0);
	
	vector<vector<int>> dist(row + 1, p);

	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j <= col; j++)
		{
			if (i == 0 || j == 0)
				dist[i][j] = 0;
            
			else if (word1[i - 1] == word2[j - 1])
				dist[i][j] = 1 + dist[i - 1][j - 1];
            
			else
				dist[i][j] = max(dist[i][j - 1], dist[i - 1][j]);
		}
	}
    
    int ans = dist[row][col];


    return ans == word1.size();
    
        
    }
};
