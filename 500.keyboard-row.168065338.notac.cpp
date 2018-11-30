/*
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (60.62%)
 * Total Accepted:    72.9K
 * Total Submissions: 120.3K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given a List of words, return the words that can be typed using letters of
 * alphabet on only one row's of American keyboard like the image
 * below. 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 * 
 * 
 * 
 * Note:
 * 
 * You may use one character in the keyboard more than once.
 * You may assume the input string will only contain letters of alphabet.
 * 
 * 
 */
class Solution {
public:

vector<string> findWords(vector<string>& words) {
	string one = "qwertyuiop";
	string two = "asdfghjkl";
	string three = "zxcvbnm";
	sort(one.begin(), one.end());
	sort(two.begin(), two.end());
	sort(three.begin(), three.end());
    
    	cout << one << endl;
	cout << two << endl;
	cout << three << endl;
	
	vector<string> ans;
	for (int i = 0; i < words.size(); i++)
	{
		string orgstr = words[i];
		for (int j = 0; j < words[i].size(); j++)
		{
			words[i][j] = tolower(words[i][j]);
		}

		sort(words[i].begin(), words[i].end());


		
		vector<char> newword;
		newword.push_back(words[i][0]);

		for (int j = 1; j < words[i].size(); j++)
		{
			if (words[i][j] != words[i][j-1])
			{
				newword.push_back(words[i][j]);
			}
		}
		newword.push_back('\0');
		string str(newword.begin(), newword.end());
		cout << str;
	
		if (str.find(one) != std::string::npos || str.find(two) != std::string::npos  || str.find(three) != std::string::npos)
		{
			ans.push_back(orgstr);
		}

	}
	return ans;
}

};
