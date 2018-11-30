/*
 * [163] Missing Ranges
 *
 * https://leetcode.com/problems/missing-ranges/description/
 *
 * algorithms
 * Medium (22.78%)
 * Total Accepted:    46.6K
 * Total Submissions: 204.4K
 * Testcase Example:  '[0,1,3,50,75]\n0\n99'
 *
 * Given a sorted integer array nums, where the range of elements are in the
 * inclusive range [lower, upper], return its missing ranges.
 * 
 * Example:
 * 
 * 
 * Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
 * Output: ["2", "4->49", "51->74", "76->99"]
 * 
 * 
 */
class Solution {
public:
//  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
//  {
// 	 vector<string> ans;
	 
//      if (!nums.size())
//      {
//         if(lower == upper) {ans.push_back(to_string(lower)); return ans;}
//         else
//         {
//             ans.push_back(to_string(lower)+ "->" + to_string(upper));
//             return ans;
//         }
//      }
     
// 	 if (lower < nums[0])
// 		 nums.insert(nums.begin(), lower);

// 	 if (upper > nums[nums.size() - 1])
// 		 nums.push_back(upper+1);
    
//      cout << "here";
// 	 for (int i = 1; i < nums.size(); i++)
// 	 {
// 		 if (nums[i] - nums[i - 1] > 1)
// 		 {
// 			 if (nums[i - 1] + 1 == nums[i] - 1)
// 				 ans.push_back(to_string(nums[i - 1] + 1));
// 			 else
// 				 ans.push_back(to_string(nums[i - 1] + 1)+ "->" + to_string(nums[i] - 1));
// 		 }

// 	 }
// 	 return ans;
//  }
    
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        nums.insert(nums.begin(), lower);
        nums.push_back(upper);
        int n = nums.size();
        vector<string> res;
        for (int i = 1; i < n; i++) {
            long  dis = (long)nums[i] - (long)nums[i - 1] + (i == 1 ? 1 : 0) + (i == n - 1 ? 1 : 0);
            if (dis == 2)
                res.push_back(to_string(nums[i] - (i == n - 1 ? 0 : 1)));
            else if (dis > 2)
                res.push_back(to_string(nums[i - 1] + (i == 1 ? 0 : 1)) + "->" + to_string(nums[i] - (i == n - 1 ? 0 : 1)));
        }
        return res;
    }
    
    
};
