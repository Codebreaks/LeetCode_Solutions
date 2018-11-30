/*
 * [386] Lexicographical Numbers
 *
 * https://leetcode.com/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (43.37%)
 * Total Accepted:    33.1K
 * Total Submissions: 76.3K
 * Testcase Example:  '13'
 *
 * 
 * Given an integer n, return 1 - n in lexicographical order.
 * 
 * 
 * 
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 * 
 * 
 * 
 * Please optimize your algorithm to use less time and space. The input size
 * may be as large as 5,000,000.
 * 
 */
class Solution {
public:
// vector<int> lexicalOrder(int n) {

// 	vector<string> result;
// 	for (int i = 1; i <= n ; i++)
// 	{
// 		result.push_back(to_string(i));
// 	}
// 	sort(result.begin(), result.end());

// 	vector<int> sendback;
// 	for (int i = 0; i < result.size(); i++)
// 	{
// 		sendback.push_back(atoi(result[i].c_str()));
// 	}
// 	return sendback;
// }
    
     vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1;
        for (int i = 0; i < n; i++) {
            res[i] = cur;
            if (cur * 10 <= n) {
                cur *= 10;
            } else {
                if (cur >= n) 
                    cur /= 10;
                cur += 1;
                while (cur % 10 == 0)
                    cur /= 10;
            }
        }
        return res;
    }
};
