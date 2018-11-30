/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (22.11%)
 * Total Accepted:    390.5K
 * Total Submissions: 1.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
vector<vector<int> > threeSum(vector<int>& nums) {
    if(nums.size() <=2) return {};
    vector<vector<int> > rtn;
    sort(nums.begin(), nums.end());
    
    for(int i =0; i < nums.size();){
        int start = i+1, end = nums.size()-1;
        

        while(start < end){
            if(nums[i]+nums[start]+nums[end] == 0)
            {
                rtn.push_back({nums[i],nums[start],nums[end]});
                start++;
                end--;
                while((start < end) && nums[start] == nums[start-1]) start++; // duplicates
                while((start < end) && nums[end] == nums[end+1]) end--; // duplicates

            }else if(nums[i]+nums[start]+nums[end]<0){
                start++;
                while((start < end) && nums[start] == nums[start-1]) start++;
            }else{
                end--;
                while((start < end) && nums[end] == nums[end+1]) end--;
            }
        }
        
        i++;
        while((i < nums.size()) && nums[i] == nums[i-1]) // duplicates
            i++;
        
    }
    return rtn;
}
    
    
// vector<vector<int>> threeSum(vector<int>& nums) 
// {
// 	vector<vector<int>> ans;
// 	if (nums.size() < 3) return ans;
// 	sort(nums.begin(), nums.end());
// 	unordered_map<int, int> holder;
// 	unordered_map<int, int>::iterator itr;
// 	bool first = true;

// 	vector<int> temp;
// 	int target = 0;

// 	for (int i = 0; i < nums.size()-2; i++)
// 	{
// 		temp.push_back(nums[i]);
// 		target -= nums[i];
		

// 		for (int j = i+1; j < nums.size(); j++)
// 		{
// 			if ((j != i + 1) && (nums[j] == nums[j - 1])) continue;

// 			itr = holder.find(target - nums[j]);
// 			if (itr != holder.end())
// 			{
// 				temp.push_back(nums[j]);
// 				temp.push_back(itr->first);
// 				ans.push_back(temp);
// 				holder.clear();
// 				break;

// 			}
// 			else
// 				holder.insert(pair<int, int>(nums[j], 0));
// 		}
// 		first = false;
// 		target = 0;
// 		temp.clear();
//         holder.clear();
// 	}
// 	return ans;
// }
    
};
