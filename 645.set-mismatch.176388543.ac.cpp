/*
 * [645] Set Mismatch
 *
 * https://leetcode.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (39.77%)
 * Total Accepted:    35.1K
 * Total Submissions: 88.2K
 * Testcase Example:  '[1,2,2,4]'
 *
 * 
 * The set S originally contains numbers from 1 to n. But unfortunately, due to
 * the data error, one of the numbers in the set got duplicated to another
 * number in the set, which results in repetition of one number and loss of
 * another number. 
 * 
 * 
 * 
 * Given an array nums representing the data status of this set after the
 * error. Your task is to firstly find the number occurs twice and then find
 * the number that is missing. Return them in the form of an array.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 * 
 * 
 * 
 * Note:
 * 
 * The given array size will in the range [2, 10000].
 * The given array's numbers won't have any order.
 * 
 * 
 */
class Solution {
public:



vector<int> findErrorNums(vector<int>& nums) 
{
	
	sort(nums.begin(), nums.end());

	vector<int> ans;

	bool xorb = false;

	int missing = 0;
	int returnnum = 0;
	int index = 1;

	for (int i = 1; i < nums.size(); i++)
	{
		if (xorb)
		{
            break;
		}
		if ((nums[i - 1] ^ nums[i]) == 0  && !xorb) 
		{
			ans.push_back(nums[i]); xorb = true; missing = nums[i];
		}
	}

		if (xorb)
		{
			returnnum = ((nums.size())*(nums.size() + 1)) / 2;

			int tSum = 0;
			for (auto x : nums) {
				tSum += x;
			}
			cout << "tsum " << tSum << endl;
			cout << "restum " << returnnum << endl;
			returnnum = (returnnum - tSum) + missing;

			ans.push_back(returnnum);
			return ans;
		}
}
    
    
};
