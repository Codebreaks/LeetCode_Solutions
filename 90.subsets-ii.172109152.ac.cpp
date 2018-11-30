/*
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (39.86%)
 * Total Accepted:    167.3K
 * Total Submissions: 419.7K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
class Solution {
public:
    
        

    
    
void subsetDFS2(vector<vector<int>>& ans, vector<int> curList, vector<int>& nums, int start)
{
	ans.push_back(curList);
	for (int i = start; i < nums.size(); i++)
	{
		if (i > start && nums[i] == nums[i - 1]) continue; // skip duplicates
		curList.push_back(nums[i]);
		subsetDFS2(ans, curList, nums, i + 1);
		curList.pop_back();
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	vector<vector<int>> ans;
	vector<int> curList;
	sort(nums.begin(), nums.end());
	subsetDFS2(ans, curList, nums, 0);
	return ans;
}
    
};
