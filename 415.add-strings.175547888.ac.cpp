/*
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (42.16%)
 * Total Accepted:    69.6K
 * Total Submissions: 165K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:

string addStrings(string num1, string num2) 
{
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	string ansstring;
	int carry = 0;
	int index = 0;
	int sum = 0;
	while (num1[index] != '\0' && num2[index] != '\0')
	{
		sum = num1[index] - '0';
		sum += num2[index] - '0';
		sum += carry;

		ansstring += to_string(sum % 10);
		carry = (sum / 10);

		index++;
		sum = 0;
	}
    
    cout << carry;

	if (index == num1.size()) //num1 finished process num2
	{
		while (num2[index] != '\0')
		{
			sum += num2[index] - '0';
			sum += carry;

			ansstring += to_string(sum % 10);
			carry = (sum / 10);

			index++;
			sum = 0;

		}
	}
	else //process num1
	{
		while (num1[index] != '\0')
		{
			sum += num1[index] - '0';
			sum += carry;

			ansstring += to_string(sum % 10);
			carry = (sum / 10);

			index++;
			sum = 0;
		}
	}

	if (carry) ansstring += to_string(carry);

	reverse(ansstring.begin(), ansstring.end());
	return ansstring;

}
    
};
