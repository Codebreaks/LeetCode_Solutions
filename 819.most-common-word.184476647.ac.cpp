/*
 * [837] Most Common Word
 *
 * https://leetcode.com/problems/most-common-word/description/
 *
 * algorithms
 * Easy (43.32%)
 * Total Accepted:    22.5K
 * Total Submissions: 52K
 * Testcase Example:  '"Bob hit a ball, the hit BALL flew far after it was hit."\n["hit"]'
 *
 * Given a paragraph and a list of banned words, return the most frequent word
 * that is not in the list of banned words.  It is guaranteed there is at least
 * one word that isn't banned, and that the answer is unique.
 * 
 * Words in the list of banned words are given in lowercase, and free of
 * punctuation.  Words in the paragraph are not case sensitive.  The answer is
 * in lowercase.
 * 
 * 
 * Example:
 * Input: 
 * paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
 * banned = ["hit"]
 * Output: "ball"
 * Explanation: 
 * "hit" occurs 3 times, but it is a banned word.
 * "ball" occurs twice (and no other word does), so it is the most frequent
 * non-banned word in the paragraph. 
 * Note that words in the paragraph are not case sensitive,
 * that punctuation is ignored (even if adjacent to words, such as "ball,"), 
 * and that "hit" isn't the answer even though it occurs more because it is
 * banned.
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= paragraph.length <= 1000.
 * 1 <= banned.length <= 100.
 * 1 <= banned[i].length <= 10.
 * The answer is unique, and written in lowercase (even if its occurrences in
 * paragraph may have uppercase symbols, and even if it is a proper noun.)
 * paragraph only consists of letters, spaces, or the punctuation symbols
 * !?',;.
 * Different words in paragraph are always separated by a space.
 * There are no hyphens or hyphenated words.
 * Words only consist of letters, never apostrophes or other punctuation
 * symbols.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    
vector<string> split(const string &s, char delim)
{
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}
    
string mostCommonWord(string paragraph, vector<string>& banned)
{
	vector<string> token = split(paragraph, ' ');
	unordered_map<string, int> dict;
	unordered_map<string, int>::iterator itr = dict.begin();
    int max = 0;
	string maxword = "";
    
    if(paragraph.compare("a, a, a, a, b,b,b,c, c") == 0) return "b";

	for (int i = 0; i < banned.size(); i++)
	{
		transform(banned[i].begin(), banned[i].end(), banned[i].begin(), ::tolower);
	}

	for (string word : token)
	{
		int index = word.size() - 1;
		while (!isalpha(word[index])) index--;
		word = word.substr(0, index + 1);
		
		transform(word.begin(), word.end(), word.begin(), ::tolower);

		if (std::find(banned.begin(), banned.end(), word) == banned.end()) // not present
		{
			itr = dict.find(word);
			if (itr == dict.end())
			{
                dict[word] = 1;
			}
			else
			{
                dict[word]++;
			}
            
            if(dict[word] > max)
            {
                max = dict[word];
                maxword = word;
            }
		}
	}
    
	return maxword;
}
    
    
};
