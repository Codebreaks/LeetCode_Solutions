/*
 * [916] Decoded String at Index
 *
 * https://leetcode.com/problems/decoded-string-at-index/description/
 *
 * algorithms
 * Medium (22.14%)
 * Total Accepted:    3.6K
 * Total Submissions: 16.4K
 * Testcase Example:  '"leet2code3"\n10'
 *
 * An encoded string S is given.  To find and write the decoded string to a
 * tape, the encoded string is read one character at a time and the following
 * steps are taken:
 * 
 * 
 * If the character read is a letter, that letter is written onto the tape.
 * If the character read is a digit (say d), the entire current tape is
 * repeatedly written d-1 more times in total.
 * 
 * 
 * Now for some encoded string S, and an index K, find and return the K-th
 * letter (1 indexed) in the decoded string.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "leet2code3", K = 10
 * Output: "o"
 * Explanation: 
 * The decoded string is "leetleetcodeleetleetcodeleetleetcode".
 * The 10th letter in the string is "o".
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "ha22", K = 5
 * Output: "h"
 * Explanation: 
 * The decoded string is "hahahaha".  The 5th letter is "h".
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: S = "a2345678999999999999999", K = 1
 * Output: "a"
 * Explanation: 
 * The decoded string is "a" repeated 8301530446056247680 times.  The 1st
 * letter is "a".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= S.length <= 100
 * S will only contain lowercase letters and digits 2 through 9.
 * S starts with a letter.
 * 1 <= K <= 10^9
 * The decoded string is guaranteed to have less than 2^63 letters.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:

// string decodeAtIndex(string S, int K) 
// {
// 	string ans;

// 	for (int i = 0; i < S.size(); i++)
// 	{
// 		if (isdigit(S[i]))
// 		{
// 			int p = S[i] - '0';
// 			p--;
// 			string org = ans;
            
// 			while (p)
// 			{
// 				ans += org;
// 				p--;
// 				if (ans.size() > K) break;
// 			}
// 		}
// 		else 
// 		{
// 			ans += S[i];
// 			if (ans.size() > K) break;
// 		}
// 	}
// 	// cout << ans;
    
// 	return ans.substr(K-1, 1);
// }
    
    string decodeAtIndex(string &S, int K, long long len = 0) 
    {
  for (auto i = 0; i < S.size(); ++i) {
    if (isalpha(S[i])) {
      if (++len == K) return string(1, S[i]);
    }
    else {
      if (len * (S[i] - '0') >= K) return decodeAtIndex(S, K % len == 0 ? len : K % len);
      len *= S[i] - '0';
    }
  }
}
    
};
