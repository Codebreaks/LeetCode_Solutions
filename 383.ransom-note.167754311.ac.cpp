/*
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (48.36%)
 * Total Accepted:    91.5K
 * Total Submissions: 189.1K
 * Testcase Example:  '"a"\n"b"'
 *
 * 
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the
 * ransom 
 * note can be constructed from the magazines ; otherwise, it will return
 * false. 
 * 
 * 
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 * 
 * 
 * Note:
 * You may assume that both strings contain only lowercase letters.
 * 
 * 
 * 
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 * 
 * 
 */
class Solution {
public:
bool canConstruct(string ransomNote, string magazine) {
	int index[256] = { 0 };
	for (int i = 0; i < magazine.size(); i++) index[magazine[i]]++;
	for (int j = 0; j < ransomNote.size(); j++)
	{
		index[ransomNote[j]]--;
		if (index[ransomNote[j]] < 0) return false;
	}
	return true;
}
};
