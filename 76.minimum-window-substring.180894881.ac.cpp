/*
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (28.27%)
 * Total Accepted:    175.7K
 * Total Submissions: 621.5K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */
class Solution {
public:

 string minWindow(string s, string t) 
 {
	 if (!s.size() || !t.size()) return "";
     
	 map<char, int> tmdict;
	 map<char, int> winddict;

	 for (char x : t)
		 tmdict[x] += 1;

	 int required = tmdict.size();
	 int formed = 0;
	 int a[3] = { -1,0,0 };
	 int l = a[1];
	 int r = a[2];
	 bool setleft = true;

	 while (r < s.size())
	 {
		 char c = s[r];
         
		 winddict[c] += 1;

		 if (tmdict.find(c) != tmdict.end() && tmdict[c] == winddict[c]) formed++;

		 while(formed == required && (l <= r))
		 {
			 if (a[0] == -1 || a[0] > (r - l + 1))
			 {
				 a[0] = (r - l + 1);               
				 a[1] = l;
				 a[2] = r;
			 }

			 char p = s[l];
			 winddict[p] -= 1;
             
			 if (tmdict.find(p) != tmdict.end() && winddict[p] < tmdict[p])
			 {
				 formed--;
			 }

             l++;
		 }
		 r++;
	 }
	 return a[0] == -1 ? "" : s.substr(a[1], (a[2] - a[1] + 1));
 }
    
};
