/*
 * [395] Longest Substring with At Least K Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (36.40%)
 * Total Accepted:    32.7K
 * Total Submissions: 89.9K
 * Testcase Example:  '"aaabb"\n3'
 *
 * 
 * Find the length of the longest substring T of a given string (consists of
 * lowercase letters only) such that every character in T appears no less than
 * k times.
 * 
 * 
 * Example 1:
 * 
 * Input:
 * s = "aaabb", k = 3
 * 
 * Output:
 * 3
 * 
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s = "ababbc", k = 2
 * 
 * Output:
 * 5
 * 
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is
 * repeated 3 times.
 * 
 * 
 */
class Solution {
public:
    
     bool isValid(map<char, int>& dict, int k)
 {
	 for (pair<char, int> p : dict)
		 if (p.second < k) return false;
    
         return true;

 }
    
 int longestSubstring(string s, int k) {

	 if(!s.size()) return 0;
     map<char, int> winddict;
	 int ans = 0;
	 int l = 0;
	 int r = 0;

	 while (r < s.size())
	 {
		 winddict[s[r]]++;
		 if (isValid(winddict, k))
		 {
			 ans = max(ans, r+1);
		 }
		 r++;
	 }
	 r--;
	 while (l < s.size())
	 {
		 winddict[s[l]]--;
		 if (isValid(winddict, k))
		 {
			 ans = max(ans, r - l + 1);
		 }
		 l++;
	 }
	 return ans;
 }
};
