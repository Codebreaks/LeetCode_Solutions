/*
 * [477] Total Hamming Distance
 *
 * https://leetcode.com/problems/total-hamming-distance/description/
 *
 * algorithms
 * Medium (47.86%)
 * Total Accepted:    39.1K
 * Total Submissions: 81.6K
 * Testcase Example:  '[4,14,2]'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * 
 * Now your job is to find the total Hamming distance between all pairs of the
 * given numbers.
 * 
 * 
 * Example:
 * 
 * Input: 4, 14, 2
 * 
 * Output: 6
 * 
 * Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is
 * 0010 (just
 * showing the four bits relevant in this case). So the answer will be:
 * HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2
 * + 2 + 2 = 6.
 * 
 * 
 * 
 * Note:
 * 
 * Elements of the given array are in the range of 0  to 10^9
 * Length of the array will not exceed 10^4. 
 * 
 * 
 */
class Solution {
public:
int hammingDistance(int x, int y) {

	int z = x ^ y;
	int count = 0;
	while(z)
	{
		if (z & 1) count++;
		z = z >> 1;
	}
	return count;

}

void getTotalHam(vector<int>& nums, vector<int>& list, int& ans, int start)
{
	if (list.size() == 2)
	{
		ans += hammingDistance(list[0], list[1]);
		return;
	}

	for (int i = start; i < nums.size(); i++)
	{
		list.push_back(nums[i]);
		getTotalHam(nums, list, ans, start);
		list.pop_back();
	}
}

int totalHammingDistance(vector<int>& nums) {

	int ans = 0;
	vector<int> list;
	getTotalHam(nums, list, ans, 0);
    return ans/2;
}
};
