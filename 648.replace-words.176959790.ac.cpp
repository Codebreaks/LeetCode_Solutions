/*
 * [648] Replace Words
 *
 * https://leetcode.com/problems/replace-words/description/
 *
 * algorithms
 * Medium (49.15%)
 * Total Accepted:    23.6K
 * Total Submissions: 48K
 * Testcase Example:  '["cat", "bat", "rat"]\n"the cattle was rattled by the battery"'
 *
 * 
 * In English, we have a concept called root, which can be followed by some
 * other words to form another longer word - let's call this word successor.
 * For example, the root an, followed by other, which can form another word
 * another.
 * 
 * 
 * 
 * 
 * Now, given a dictionary consisting of many roots and a sentence. You need to
 * replace all the successor in the sentence with the root forming it. If a
 * successor has many roots can form it, replace it with the root with the
 * shortest length.
 * 
 * 
 * 
 * You need to output the sentence after the replacement.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: dict = ["cat", "bat", "rat"]
 * sentence = "the cattle was rattled by the battery"
 * Output: "the cat was rat by the bat"
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The input will only have lower-case letters.
 * ⁠1 
 * ⁠1 
 * ⁠1 
 * ⁠1 
 * 
 * 
 */
class Solution {
public:
string replaceWords(vector<string>& dict, string sentence) 
{
	// sort(dict.begin(), dict.end());

	regex reg("\\s+");
	sregex_token_iterator iter(sentence.begin(), sentence.end(), reg, -1);
	sregex_token_iterator end;
	vector<string> tokens(iter, end);
	string ans;
	bool found = false;

	for (int i = 0; i < tokens.size(); i++)
	{
		for (int j = 0; j < dict.size(); j++)
		{
			if (tokens[i].compare(0, dict[j].size(), dict[j]) == 0)
			{
				ans += dict[j] + " ";
				found = true;
				break;
			}
		}
		if (!found) ans += tokens[i] + " ";
        found = false;
	}
    ans = ans.substr(0, ans.size() - 1);
	return ans;
}
};
