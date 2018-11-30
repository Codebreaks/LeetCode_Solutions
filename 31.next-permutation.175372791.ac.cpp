/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (29.28%)
 * Total Accepted:    177.8K
 * Total Submissions: 607.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
    
    void swap(vector<int>& nums, int k, int l)
{
	int temp = nums[k];
	nums[k] = nums[l];
	nums[l] = temp;
}
    
void nextPermutation(vector<int>& nums) {
	
	bool sorteddec = true;

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] > nums[i - 1])
		{
			sorteddec = false;
			break;
		}
	}
	if (sorteddec)  return reverse(nums.begin(), nums.end());
	int k = 0;
	int l = 0;

	for ( k = nums.size()-2; k > -1; k--)
	{
		if (nums[k] < nums[k + 1]) break;
	}

	for (l = nums.size() - 1; l > k; l--)
	{
		if (nums[l] > nums[k]) break;
	}
	swap(nums, k, l);


	k = k+1;
	l = nums.size()-1;
	while (k<l)
	{
		swap(nums, k, l);
		k++;
		l--;
	}
}
};
