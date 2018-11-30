/*
 * [808] Number of Matching Subsequences
 *
 * https://leetcode.com/problems/number-of-matching-subsequences/description/
 *
 * algorithms
 * Medium (38.29%)
 * Total Accepted:    11.2K
 * Total Submissions: 29.1K
 * Testcase Example:  '"abcde"\n["a","bb","acd","ace"]'
 *
 * Given string S and a dictionary of words words, find the number of words[i]
 * that is a subsequence of S.
 * 
 * 
 * Example :
 * Input: 
 * S = "abcde"
 * words = ["a", "bb", "acd", "ace"]
 * Output: 3
 * Explanation: There are three words in words that are a subsequence of S:
 * "a", "acd", "ace".
 * 
 * 
 * Note:
 * 
 * 
 * All words in words and S will only consists of lowercase letters.
 * The length of S will be in the range of [1, 50000].
 * The length of words will be in the range of [1, 5000].
 * The length of words[i] will be in the range of [1, 50].
 * 
 */
class Solution {
public:
int numMatchingSubseq(string S, vector<string>& words) 
 {
	 unordered_map<char, int> locs;
	 unordered_map<char, int>::iterator itr;
    
     unordered_map<char, int> locsrev;
	 unordered_map<char, int>::iterator itr2;

	 for (int i = S.size()-1; i >= 0; i--)
	 {
		 locs[S[i]] = i;
	 }
    
     for (int i = 0; i < S.size(); i++)
	 {
		 locsrev[S[i]] = i;
	 }

	 int last = 0;
	 int total = 0;
	 
	 for (int i = 0; i < words.size(); i++)
	 {
		 string cur = words[i];

		 itr = locs.find(cur[0]);
		 
		 if (cur.size() > 1)
		 {
			 int last = 0;
             
			 if (itr == locs.end()) continue;
			 else
				 last = itr->second;
			 
			 int j = 1;
             
			 for (j = 1; j < cur.size(); j++)
			 {
				 if (locs[cur[j]] > last) 
				 {
					 last = locs[cur[j]];
				 }
				 else
				 {
					 break;
				 }
			 }
             
			 if (j == cur.size()) ++total;
		 }
		 else
		 {
			 if ( itr != locs.end()) ++total;
		 }
         
         
         itr2 = locsrev.find(cur[0]);;
         
         if (cur.size() > 1)
		 {
			 int last = 0;
             
			 if (itr2 == locsrev.end()) continue;
			 else
				 last = itr2->second;
			 
			 int j = 1;
             cout << "here";
             
			 for (j = 1; j < cur.size(); j++)
			 {
				 if (locsrev[cur[j]] > last) 
				 {
					 last = locsrev[cur[j]];
				 }
				 else
				 {
					 break;
				 }
			 }
             
			 if (j == cur.size()) ++total;
		 }
         
         
         
	 }

return total; 
}
};
