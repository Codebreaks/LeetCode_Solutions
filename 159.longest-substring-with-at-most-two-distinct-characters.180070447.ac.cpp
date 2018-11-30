/*
 * [159] Longest Substring with At Most Two Distinct Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/
 *
 * algorithms
 * Hard (44.24%)
 * Total Accepted:    52.4K
 * Total Submissions: 118.4K
 * Testcase Example:  '"eceba"'
 *
 * Given a string s , find the length of the longest substring t  that contains
 * at most 2 distinct characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "eceba"
 * Output: 3
 * Explanation: t is "ece" which its length is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "ccaabbb"
 * Output: 5
 * Explanation: t is "aabbb" which its length is 5.
 * 
 * 
 */
class Solution {
public:
 int lengthOfLongestSubstringTwoDistinct(string s) 
 {
	 if (!s.size()) return 0;

	 int len = INT_MIN;
	 int distinct = 0;
	 map<char, int> fremap;
	 int start, end;
	 start = end = 0;

	 while (end < s.size())
	 {
		 char c = s[end];
		 if (fremap[c] == 0)
		 {
			 fremap[c] = 1;
			 distinct++;
		 }
         else
             fremap[c]++;

		 if (distinct == 2)
		 {
		 len = max(len, end - start + 1);
		 }

		 while (distinct > 2)
		 {
			 char rem = s[start];
			 fremap[rem]--;
			 if (fremap[rem] == 0) --distinct;
			 start++;
		 }

		 len = max(len, end - start + 1);
         end++;
	 }
     
	 return len;
 }
    
};
