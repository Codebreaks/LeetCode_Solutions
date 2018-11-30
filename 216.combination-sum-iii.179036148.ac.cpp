/*
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (48.82%)
 * Total Accepted:    101K
 * Total Submissions: 206.9K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 * 
 */
class Solution {
public:

    int combination = 0;
    int target =0;

    
    
    void subsetDFS(vector<vector<int>>& ans, vector<int> curList, int sum, int start)
{
	if(curList.size() == combination)
    {
        if(sum == target)
            ans.push_back(curList);
        
        return;
    }

    if(sum > target) return;
    
	for (int i = start ; i <= 9; i++)
	{
		curList.push_back(i);
        sum += i;
		subsetDFS(ans, curList, sum, i+1);
        sum -= i;
		curList.pop_back();
	}
}

vector<vector<int>> combinationSum3(int k, int n) 
{

	vector<vector<int>> ans;
	vector<int> curList;
    
    combination = k;
    target = n;
    int sum = 0;
    
	subsetDFS(ans, curList, sum, 1);
	return ans;
}
};
