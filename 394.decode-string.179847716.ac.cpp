/*
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (42.29%)
 * Total Accepted:    68.8K
 * Total Submissions: 162.8K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 
 * Given an encoded string, return it's decoded string.
 * 
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * 
 * Examples:
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 */
class Solution {
public:
string decodeString(string s) {
	if (s == "") return "";
	stack<char> holder;
	string result = "";
	int i = 0;

	while (s[i] != '\0')
	{
		
        if (s[i] != ']')
		{
			holder.push(s[i]);
		}
		else
		{
			
            string word = "";
			while (holder.top() != '[')
			{
				word = holder.top() + word;
				holder.pop();
			}
            
			holder.pop(); 

            string number = "";
            while(!holder.empty() && holder.top() < 'a' && holder.top() != '[')
            {
                number = holder.top() + number;
                cout << number << endl;
                holder.pop();
            }
            
            int counter = atoi(number.c_str());
            counter--;
            
            
            string ord = word;
			
            while (counter)
			{
				word = word + ord;
                counter =  counter -  1;
			}
            
			for (int j = 0; j < word.size(); j++)
			{
				holder.push(word[j]);
			}
		}
        
		i++;
	}
    
	while (!holder.empty())
	{
		result = holder.top() + result;
		holder.pop();
	}
    
	return result;
}
};
