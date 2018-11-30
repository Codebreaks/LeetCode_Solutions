/*
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (36.66%)
 * Total Accepted:    29.7K
 * Total Submissions: 81.1K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 * 
 * Example 1:
 * 
 * Input:s1 = "ab" s2 = "eidbaooo"
 * Output:True
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 * 
 * 
 * 
 * Note:
 * 
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 * 
 * 
 */
class Solution {
public:
 bool issubstring(int l, int r, string& s2, string& s1)
 {
	 sort(s1.begin(), s1.end());
	 string extstr = s2.substr(l, r-l+1);
	 sort(extstr.begin(), extstr.end());
	 return s1.compare(extstr) == 0 ? true : false;
 }

 int computeHash(int l, int r, string& S)
 {
	 int ans = 0;
	 for (int i = l; i <= r; i++)
	 {
		 ans += S[i] - 'a';
	 }
     // cout << ans << endl;
	 return ans;
 }

 bool checkInclusion(string s1, string s2) 
 {
	 if (!s1.size() && !s2.size()) return true;

	 int l = 0;
	 int r = s1.size()-1;
	 int hash = 0;
	 int lastChar = '\0';
	 int hashtemp = computeHash(0, s1.size()-1, s1);
	 

	 while (r < s2.size())
	 {
		 if (!hash)
			 hash = computeHash(l, r, s2);
		 else{
			 hash -= s2[l - 1];
			 hash += s2[r];
		 }

		 if (hash == hashtemp && issubstring(l, r, s2, s1)) return true;
		 else
		 {
			 l++;
			 r++;
		 }
	 }
	 return false;
 }

};
