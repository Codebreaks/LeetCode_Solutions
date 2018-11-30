/*
 * [491] Increasing Subsequences
 *
 * https://leetcode.com/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (39.79%)
 * Total Accepted:    24.1K
 * Total Submissions: 60.5K
 * Testcase Example:  '[4,6,7,7]'
 *
 * 
 * Given an integer array, your task is to find all the different possible
 * increasing subsequences of the given array, and the length of an increasing
 * subsequence should be at least 2 .
 * 
 * 
 * Example:
 * 
 * Input: [4, 6, 7, 7]
 * Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
 * [4,7,7]]
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array will not exceed 15.
 * The range of integer in the given array is [-100,100].
 * The given array may contain duplicates, and two equal integers should also
 * be considered as a special case of increasing sequence.
 * 
 * 
 */
class Solution {
public:
    
vector<vector<int>> findSubsequences(vector<int>& nums)
{
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
    
	int maxsubsets = pow(2, nums.size());
	
    for (int i = 0; i < maxsubsets; i++)
	{
		vector<int> current;
        
		int j = 1, count = nums.size();
        
        // cout << i << endl;
        
        int pos = 0;
        
		while (count)
		{
			if (i & j) 
            {
                current.push_back(nums[pos]);
                cout << nums[pos] ;
            }
            
			j = j << 1;
			--count;
            pos++;
		}
        cout<<endl;

		
		if (current.size() >= 2)
		{
            ans.push_back(current);
// 			reverse(current.begin(), current.end());
// 			bool increasing = true;
// 			int i = 1;
            
// 			while (i < current.size())
// 			{
// 				if (current[i] < current[i-1])
// 				{
// 					increasing = false;
// 					break;
// 				}
//                 i++;
// 			}

// 			if (increasing)
// 			{
// 				ans.push_back(current);
// 			}
		}

	}
	return ans;
}
};
