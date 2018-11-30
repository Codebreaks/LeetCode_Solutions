/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (37.96%)
 * Total Accepted:    174.6K
 * Total Submissions: 460K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
class Solution {
public:

void subsetDFS(vector<vector<int>>& ans, vector<int> curList, vector<int>& nums, int target, int start)
{
	if(target == 0)
    {
        ans.push_back(curList);
        return;
    }
    
    if(target < 0) return;
        
    
	for (int i = start; i < nums.size(); i++)
	{
        
       if (i > start && nums[i] == nums[i-1]) continue;
        
        curList.push_back(nums[i]);
        target -= nums[i];
		subsetDFS(ans, curList, nums, target, (i+1));
        target += nums[i];
		curList.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
	vector<vector<int>> ans;
	vector<int> curList;
    sort(candidates.begin(), candidates.end());
	subsetDFS(ans, curList, candidates, target, 0);
	return ans;
}
    
};
