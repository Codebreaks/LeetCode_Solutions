/*
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (28.73%)
 * Total Accepted:    158.4K
 * Total Submissions: 551.3K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:

    string multiply(string num1, string num2) 
{
	int m = num1.size();
	int n = num2.size();
	string ans((m+n),'0');
    
	int carry = 0;
	int tempsum = 0;

	for (int i = m-1; i >= 0; i--) //num1
	{
		for (int j = n - 1; j >= 0; j--) //num2
		{
			tempsum = (num1[i] - '0') *  (num2[j] - '0') + carry + (ans[i+j+1] - '0');
            
            cout << (ans[i+j+1] - '0') << endl;
            
            cout << (tempsum % 10) ;
            
			ans[i + j + 1] = (tempsum % 10) + '0';
            
			carry = tempsum / 10;
		}
        
		ans[i] += carry;
        
		carry = 0;
	}
        
	int start = 0;
	while (start < ans.size() && ans[start] == '0' )
	{
		start++;
	}
	if (start == ans.size()) return "0";
	else return ans.substr(start);

        
        
}
    
};
