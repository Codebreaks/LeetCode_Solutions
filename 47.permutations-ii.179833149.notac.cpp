/*
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (37.02%)
 * Total Accepted:    190.5K
 * Total Submissions: 514.7K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
class Solution {
public:

    void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permutenums(vector<vector<int>>& ans, vector<int> curList, vector<int>& nums, int start)
{
	if (start == nums.size())
	{
		ans.push_back(nums);
		return;
	}
	for (int i = start; i < nums.size(); i++)
	{
		if(i > start && (nums[i] == nums[i-1])) continue;
        
        swap(&nums[start], &nums[i]);
		permutenums(ans, curList, nums, start+1);
		swap(&nums[start], &nums[i]);
	}

}

     vector<vector<int>> permuteUnique(vector<int>& nums) 
     {
        vector<vector<int>> ans;
        vector<int> curList;
        sort(nums.begin(), nums.end());
        permutenums(ans, curList, nums, 0);
        return ans;
    }
};
