/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (37.95%)
 * Total Accepted:    223.5K
 * Total Submissions: 589K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
class Solution {
public:
void buildtable(vector<string>& v, int n)
{
	while (v.size() < n)
	{
        string last = v[v.size() - 1];
		string next = "";
		int i = 1;
		int count = 1;
		char ch = last[0];

		while (last[i] != '\0')
		{
			if (last[i] == ch)
			{
				++count;
			}
			else
			{
				next = next + to_string(count) + ch;
 				count = 1;
			}
			ch = last[i];
            i++;
		}
        
        next = next + to_string(count) + ch;
		v.push_back(next);
	}
}
    
    
void inittable(vector<string>& v)
{
	v.push_back("1");
	v.push_back("11");
	v.push_back("21");
	v.push_back("1211");
	v.push_back("111221");
}

string countAndSay(int n) {
	vector<string> table;
	inittable(table);
	buildtable(table,n);
	return table[n - 1];
}
};
