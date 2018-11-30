/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (47.91%)
 * Total Accepted:    279.8K
 * Total Submissions: 584K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:

    
    
void subsetDFS(vector<vector<int>>& ans, vector<int> curList, vector<int>& nums, int start)
{
	ans.push_back(curList);
	for (int i = start; i < nums.size(); i++)
	{
		curList.push_back(nums[i]);
		subsetDFS(ans, curList, nums, i+1);
		curList.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> ans;
	vector<int> curList;
	subsetDFS(ans, curList, nums, 0);
	return ans;
}
    
// vector<vector<int>> subsets(vector<int>& nums) 
// {
// 	vector<vector<int>> ans;
// 	int maxsubsets = pow(2, nums.size());
// 	for(int i = 0; i < maxsubsets; i++)
// 	{
// 		vector<int> current;
// 		int j = 1;
//         int count = nums.size();
//         int index = 0;
        
// 		while (count)
// 		{
// 			if(i & j) 
//             {
//                 current.push_back(nums[index]);
//             }
            
// 			j = j << 1;
// 			--count;
//             ++index;
// 		}
// 		ans.push_back(current);
// 	}
// 	return ans;
// }


};
