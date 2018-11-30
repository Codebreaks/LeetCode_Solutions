/*
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (61.60%)
 * Total Accepted:    91.4K
 * Total Submissions: 148.4K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 * 
 */
class Solution {
public:
string reverseWords(string s) {

	int i = 0;
	int j = 0;
	int terminal = 0;
    bool end = false;

	do{
            while (s[j] != ' ' && s[j] != '\0')
            {
                j++;
            }
        
            if(s[j] == '\0') end = true;
        
            int last = j - 1;
        
        while (i < last)
            {
                char temp = s[i];
                s[i] = s[last];
                s[last] = temp;
                i++;
                last--;
            }
            
            j++;
            i = j;

        
    } while(!end);
    
    
	return s;
}
};
