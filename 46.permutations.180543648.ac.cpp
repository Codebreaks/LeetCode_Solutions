/*
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (50.94%)
 * Total Accepted:    295.1K
 * Total Submissions: 579.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
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
		swap(&nums[start], &nums[i]);
		permutenums(ans, curList, nums, start+1);
		swap(&nums[start], &nums[i]);
	}

}

// vector<vector<int>> permute(vector<int>& nums) {
// 	vector<vector<int>> ans;
// 	vector<int> curList;
// 	permutenums(ans, curList, nums, 0);
// 	return ans;
// }
    
void getCombination(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curlist)
 {
	 if (curlist.size() == nums.size())
	 {
		 ans.push_back(curlist);
		 return;
	 }

	 for (int i = 0; i < nums.size(); i++)
	 {
		 if(std::find(curlist.begin(), curlist.end(), nums[i]) == curlist.end())
			curlist.push_back(nums[i]);
         else
             continue;
		 
		 getCombination(ans, nums, curlist);
		 curlist.pop_back();
	 }
 }
    
    vector<vector<int>> permute(vector<int>& nums) {
	 vector<vector<int>> ans;
	 vector<int> curlist;
	 getCombination(ans, nums, curlist);
	 return ans;
}
    
    
    
};
