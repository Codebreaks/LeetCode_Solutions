/*
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (61.50%)
 * Total Accepted:    301.6K
 * Total Submissions: 490.4K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: "hello"
 * Output: "olleh"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: "amanaP :lanac a ,nalp a ,nam A"
 * 
 * 
 * 
 * 
 */
class Solution {
public:
string reverseString (string s)
{
    if(s == "") return s;
    int i = 0;
    int j = s.size() - 1;
    while(i<j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    return s;

}

};
