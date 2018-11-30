/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (43.83%)
 * Total Accepted:    256.7K
 * Total Submissions: 585.8K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
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
		curList.push_back(nums[i]);
        target -= nums[i];
		subsetDFS(ans, curList, nums, target, i);
        target += nums[i];
		curList.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
	vector<vector<int>> ans;
	vector<int> curList;
	subsetDFS(ans, curList, candidates, target, 0);
	return ans;
}



};
