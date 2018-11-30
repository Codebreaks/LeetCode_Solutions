/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (38.26%)
 * Total Accepted:    284.3K
 * Total Submissions: 743.2K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:

void getComb(vector<char> strvec, int start, string input, vector<string>& ans, unordered_map<int, string>& dict)
{
	if (strvec.size() == input.size())
	{
		
		string scr(strvec.begin(), strvec.end());
		ans.push_back(scr);
		return;
	}

	string st = dict.find(input[start] - '0')->second;
			
	for(int j = 0; j < st.size(); j++)
	{
		strvec.push_back(st[j]);
		getComb(strvec, start+1, input, ans, dict);
		strvec.pop_back();
	}
}
    
    vector<string> letterCombinations(string digits) 
{
	vector<string> ans;
	vector<char> comb;

	if (!digits.size()) return ans;

	unordered_map<int, string> dict;
	dict.insert(pair<int, string>(2, "abc"));
	dict.insert(pair<int, string>(3, "def"));
	dict.insert(pair<int, string>(4, "ghi"));
	dict.insert(pair<int, string>(5, "jkl"));
	dict.insert(pair<int, string>(6, "mno"));
	dict.insert(pair<int, string>(7, "pqrs"));
	dict.insert(pair<int, string>(8, "tuv"));
	dict.insert(pair<int, string>(9, "wxyz"));

	getComb(comb, 0, digits, ans, dict);
	return ans;

}
};


// class Solution {
// public:
//     vector<string> letterCombinations(string digits) 
//     {
//         vector<string> res;
//         if(digits.size()==0) return res;
//         string local;
//         vector<vector<char>> table(2,vector<char>());
//         table.push_back(vector<char>{'a','b','c'}); // index 2
//         table.push_back(vector<char>{'d','e','f'}); // 3
//         table.push_back(vector<char>{'g','h','i'});
//         table.push_back(vector<char>{'j','k','l'}); // 5
//         table.push_back(vector<char>{'m','n','o'});
//         table.push_back(vector<char>{'p','q','r','s'}); // 7
//         table.push_back(vector<char>{'t','u','v'});
//         table.push_back(vector<char>{'w','x','y','z'}); // 9
        
//         backtracking(table,res,local,0,digits);
//         return res;
//     }
    
//     void backtracking(const vector<vector<char>>& table, vector<string>& res, string& local, int index, const string& digits) {
//         if(index==digits.size())
//             res.push_back(local);
//         else
//             for(int i=0; i<table[digits[index]-'0'].size();i++) 
//       			{ 
//                 local.push_back(table[digits[index]-'0'][i]);
//                 backtracking(table, res, local, index+1, digits);
//                 local.pop_back();
//             }
//     }

