/*
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (24.79%)
 * Total Accepted:    53.7K
 * Total Submissions: 216.7K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * The update(i, val) function modifies nums by updating the element at index i
 * to val.
 * 
 * Example:
 * 
 * 
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * 
 * 
 * Note:
 * 
 * 
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is
 * distributed evenly.
 * 
 * 
 */
class NumArray {
private:
	vector<int> inputnum;

public:
	NumArray(vector<int> nums)
	{
		if (nums.size())
			inputnum.push_back(nums[0]);

		for (int i = 1; i < nums.size(); i++)
		{
			inputnum.push_back(inputnum[inputnum.size()-1] + nums[i]);
		}
	}

	void update(int i, int val) 
	{
		int diff = val - (inputnum[i] - inputnum[i-1]);
        
        cout << "diff "<< diff << endl; 

		for (int k = i; k < inputnum.size(); k++)
		{
			inputnum[k] = inputnum[k] + diff;
		}
	}

	int sumRange(int i, int j)
	{
		cout << inputnum[j] << endl; 
        return inputnum[j] - (i == 0 ? 0 : inputnum[i - 1]);
	}
};






/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
