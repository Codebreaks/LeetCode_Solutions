/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (38.84%)
 * Total Accepted:    1.1M
 * Total Submissions: 2.8M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
//     vector<int> twoSum(vector<int>& nums, int target) {
        
//         vector<int> result(2);
        
        
        
//         for(int i = 0; i < nums.size() - 1; i++)
//         {
            
            
//             for(int j= i+1; j < nums.size(); j++)
//             {
//                 if(nums[i]+nums[j] == target)
//                 {
//                     result[0] = i;
//                     result[1] = j;
//                     return result;
//                 }
//             }
//         }
        
        
//     }
    
    // Using Map
    
vector<int> twoSum(vector<int>& nums, int target)
{
	map<int, int> seen;

	vector<int> a;
    
	for (int i = 0; i < nums.size(); i++)
	{
		if (seen.find(target - nums[i]) != seen.end())
		{
			a.push_back(i);
			a.push_back(seen[target - nums[i]]);
			return a;
		}
		else
		{
			seen[nums[i]] = i;
		}
	}
	return a;
}
    
    

    
};
