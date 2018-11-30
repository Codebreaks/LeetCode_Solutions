/*
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (24.31%)
 * Total Accepted:    106.6K
 * Total Submissions: 438.4K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * Example 1:
 * 
 * 
 * Input: [10,2]
 * Output: "210"
 * 
 * Example 2:
 * 
 * 
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 * 
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 */
class Solution {
public:
bool compare(int first, int second)
{
	string a = to_string(first) + to_string(second);
	string b = to_string(second) + to_string(first);
	return a.compare(b) < 0 ? true : false;
}

string largestNumber(vector<int>& nums) {

	string ans;

	for (int i = 0; i < nums.size()-1; i++)
	{
		for (int j = 1; j < nums.size()-i; j++)
		{
			if (compare(nums[j-1], nums[j]))
			{
				int temp = nums[j];
				nums[j] = nums[j - 1];
				nums[j - 1] = temp;
			}
		}
	}
	for (int i = 0; i < nums.size(); i++)
	{
		ans += to_string(nums[i]);
	}
    
	// Remove trailing
	int i = 0;
	while (ans[i] == '0')
	{
		i++;
	}

	string ansnew =  ans.substr(i);
    if(ansnew.compare("")==0) return "0";
    else
        return ansnew;
}
};
