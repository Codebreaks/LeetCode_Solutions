/*
 * [712] Minimum ASCII Delete Sum for Two Strings
 *
 * https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
 *
 * algorithms
 * Medium (52.08%)
 * Total Accepted:    13.2K
 * Total Submissions: 25.4K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * Given two strings s1, s2, find the lowest ASCII sum of deleted characters to
 * make two strings equal.
 * 
 * Example 1:
 * 
 * Input: s1 = "sea", s2 = "eat"
 * Output: 231
 * Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to
 * the sum.
 * Deleting "t" from "eat" adds 116 to the sum.
 * At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum
 * possible to achieve this.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: s1 = "delete", s2 = "leet"
 * Output: 403
 * Explanation: Deleting "dee" from "delete" to turn the string into "let",
 * adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e]
 * to the sum.
 * At the end, both strings are equal to "let", and the answer is
 * 100+101+101+101 = 403.
 * If instead we turned both strings into "lee" or "eet", we would get answers
 * of 433 or 417, which are higher.
 * 
 * 
 * 
 * Note:
 * 0 < s1.length, s2.length .
 * All elements of each string will have an ASCII value in [97, 122]. 
 * 
 */
class Solution {
public:
    int minimumDeleteSum(string word1, string word2) 
    {
        
    int row = word1.size();
	int col = word2.size();
            int sum1 = 0;

	vector<int> p(col + 1, 0);
	
	vector<vector<int>> dist(row + 1, p);

	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j <= col; j++)
		{
			if (i == 0 || j == 0)
				dist[i][j] = 0;
            
			else if (word1[i - 1] == word2[j - 1])
            {
                dist[i][j] = 1 + dist[i - 1][j - 1];
            }
				
            
			else
				dist[i][j] = max(dist[i][j - 1], dist[i - 1][j]);
		}
	}
    
    int ans = dist[row][col];

	int k = (2 * ans);
    
    cout << dist[row][col];


    int m = row;
    int n = col;
    
    // Following code is used to print LCS
   int index = dist[m][n];
 
   // Create a character array to store the lcs string
   char lcs[index+1];
   lcs[index] = '\0'; // Set the terminating character
 
   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
        
   int sum3 = 0;
        
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (word1[i-1] == word2[j-1])
      {
          lcs[index-1] = word1[i-1]; // Put current character in result
          sum3 += word1[i-1];
          i--; j--; index--;     // reduce values of i, j and index
      }
 
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (dist[i-1][j] > dist[i][j-1])
         i--;
      else
         j--;
   }
 
   // Print the lcs
   // cout << "LCS of " << word1 << " and " << word2 << " is " << lcs;
        
        cout << sum3;
    for(char c: word1)
        sum1 += c;
        
    for(char c: word2)
        sum1 += c;
        
        return (sum1 - (2*sum3));
        

   
        
        
        
        
    }
};
