/*
 * [851] Goat Latin
 *
 * https://leetcode.com/problems/goat-latin/description/
 *
 * algorithms
 * Easy (54.86%)
 * Total Accepted:    17.2K
 * Total Submissions: 31.4K
 * Testcase Example:  '"I speak Goat Latin"'
 *
 * A sentence S is given, composed of words separated by spaces. Each word
 * consists of lowercase and uppercase letters only.
 * 
 * We would like to convert the sentence to "Goat Latin" (a made-up language
 * similar to Pig Latin.)
 * 
 * The rules of Goat Latin are as follows:
 * 
 * 
 * If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of
 * the word.
 * For example, the word 'apple' becomes 'applema'.
 * 
 * If a word begins with a consonant (i.e. not a vowel), remove the first
 * letter and append it to the end, then add "ma".
 * For example, the word "goat" becomes "oatgma".
 * 
 * Add one letter 'a' to the end of each word per its word index in the
 * sentence, starting with 1.
 * For example, the first word gets "a" added to the end, the second word gets
 * "aa" added to the end and so on.
 * 
 * 
 * Return the final sentence representing the conversion from S to Goat
 * Latin. 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "I speak Goat Latin"
 * Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "The quick brown fox jumped over the lazy dog"
 * Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa
 * hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 * 
 * 
 * 
 * 
 * Notes:
 * 
 * 
 * S contains only uppercase, lowercase and spaces. Exactly one space between
 * each word.
 * 1 <= S.length <= 150.
 * 
 */
class Solution {
public:
string toGoatLatin(string S) {
	if (S == "") return "";
	string answer;
	string buf;                 // Have a buffer string
	stringstream ss(S);       // Insert the string into a stream
	vector<std::string> tokens; // Create vector to hold our words
    bool first = true;
	while (ss >> buf)
	{
		tokens.push_back(buf);
        // cout << buf << endl;
	}
	for (int i = 0; i < tokens.size(); i++)
	{
		string current = tokens[i];
		char first = current[0];
		string newword = "";
		if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u'
           || first == 'A' || first == 'E' || first == 'I' || first == 'O' || first == 'U')
		{
			newword = current + "ma";
		}
		else
		{
			newword = current.substr(1, (current.size() - 1)) + current[0] + "ma";
		}
		int counter = i + 1;
		while (counter)
		{
			newword += "a";
			--counter;
		}
        
        if(!(i == (tokens.size()-1) ))
        {
            newword += " ";
        }
        
		answer += newword;
	}
	return answer;
}
};
