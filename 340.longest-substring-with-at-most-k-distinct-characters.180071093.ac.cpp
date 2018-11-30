/*
 * [340] Longest Substring with At Most K Distinct Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/
 *
 * algorithms
 * Hard (38.53%)
 * Total Accepted:    53.9K
 * Total Submissions: 139.9K
 * Testcase Example:  '"eceba"\n2'
 *
 * Given a string, find the length of the longest substring T that contains at
 * most k distinct characters.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: s = "eceba", k = 2
 * Output: 3
 * Explanation: T is "ece" which its length is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aa", k = 1
 * Output: 2
 * Explanation: T is "aa" which its length is 2.
 * 
 * 
 * 
 * 
 */
class Solution {
public:

 int lengthOfLongestSubstringKDistinct(string s, int k) {
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

		 if (distinct == k)
		 {
		    len = max(len, end - start + 1);
		 }

		 while (distinct > k)
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
