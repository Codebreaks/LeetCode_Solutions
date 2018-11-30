/*
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (48.97%)
 * Total Accepted:    251K
 * Total Submissions: 512.6K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */
class Solution {
public:
bool isAnagram(string s, string t) {
	int a[256] = { 0 };
    
    if(s.size() != t.size()) return false;

	for(char x : s)
		a[x]++;

	for (char x : t) {
		a[x]--;
		if (a[x] < 0) return false;
	}
	return true;
}
};
