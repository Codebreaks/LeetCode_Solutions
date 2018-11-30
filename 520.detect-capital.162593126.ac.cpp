/*
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (51.83%)
 * Total Accepted:    68.5K
 * Total Submissions: 132.2K
 * Testcase Example:  '"USA"'
 *
 * 
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 * 
 * 
 * 
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital if it has more than one
 * letter, like "Google".
 * 
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "USA"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "FlaG"
 * Output: False
 * 
 * 
 * 
 * Note:
 * The input will be a non-empty word consisting of uppercase and lowercase
 * latin letters.
 * 
 */
class Solution {
public:
    bool detectCapitalUse(string word) {
        
        
	bool allUpper = true;
	bool allLower = true;
	bool firstUpper = true;
    bool otherCapital = false;

	int len = word.size();
	int i = 0;

	while (word[i] != '\0')
	{
		if (isupper(word[i]))
		{
			allUpper = allUpper && true;
			allLower = allLower && false;
            if(i>0) otherCapital = true;
		}

		else
		{
			allUpper = allUpper && false;
			allLower = allLower && true;
			if (i == 0) firstUpper = false;
		}
		i++;
	}

	return allUpper || allLower || (firstUpper && !otherCapital && (len>1));
        
    }
};
