/*
 * [583] Delete Operation for Two Strings
 *
 * https://leetcode.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (44.86%)
 * Total Accepted:    22.7K
 * Total Submissions: 50.6K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 
 * Given two words word1 and word2, find the minimum number of steps required
 * to make word1 and word2 the same, where in each step you can delete one
 * character in either string.
 * 
 * 
 * Example 1:
 * 
 * Input: "sea", "eat"
 * Output: 2
 * Explanation: You need one step to make "sea" to "ea" and another step to
 * make "eat" to "ea".
 * 
 * 
 * 
 * Note:
 * 
 * The length of given words won't exceed 500.
 * Characters in given words can only be lower-case letters.
 * 
 * 
 */
class Solution {
public:
int minDistance(string word1, string word2) 
{
	int row = word1.size();
	int col = word2.size();
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

	int k = (2 * ans);
    

    return row + col - k;  
    
    
}
    
};
