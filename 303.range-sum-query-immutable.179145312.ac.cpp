/*
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (34.30%)
 * Total Accepted:    109.7K
 * Total Submissions: 319.9K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */
class NumArray {
private:
	vector<int> inputnum;

public:
	NumArray(vector<int> nums)
	{
		
        if(nums.size())
        inputnum.push_back(nums[0]);

		for (int i = 1; i < nums.size(); i++)
		{
			inputnum.push_back(inputnum[inputnum.size()-1] + nums[i]);
		}
	}

	int sumRange(int i, int j)
	{
		return inputnum[j] - (i == 0 ? 0 : inputnum[i - 1]);
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
