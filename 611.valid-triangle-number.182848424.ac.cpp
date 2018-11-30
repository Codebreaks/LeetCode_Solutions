/*
 * [611] Valid Triangle Number
 *
 * https://leetcode.com/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (43.11%)
 * Total Accepted:    26.4K
 * Total Submissions: 61.2K
 * Testcase Example:  '[2,2,3,4]'
 *
 * Given an array consists of non-negative integers,  your task is to count the
 * number of triplets chosen from the array that can make triangles if we take
 * them as side lengths of a triangle.
 * 
 * Example 1:
 * 
 * Input: [2,2,3,4]
 * Output: 3
 * Explanation:
 * Valid combinations are: 
 * 2,3,4 (using the first 2)
 * 2,3,4 (using the second 2)
 * 2,2,3
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array won't exceed 1000.
 * The integers in the given array are in the range of [0, 1000].
 * 
 * 
 * 
 */
class Solution {
public:
// int triangleNumber(vector<int>& nums) 
// {
// 	int totalCount = 0;
// 	sort(nums.begin(), nums.end());
// 	reverse(nums.begin(), nums.end());
//     if(nums.size() < 3) return 0;

// 	int cur = 0;

// 	while (cur < (nums.size()-2))
// 	{
// 		int key = nums[cur];
// 		int start = cur + 1;
// 		int end = nums.size();
        
// 		while (start < (nums.size()-1) )
// 		{
// 			if ( (nums[start] + nums[end] ) > key)
// 			{
// 				totalCount++;
// 			}
            
// 			end--;
                
// 			if (end <= start)
// 			{
// 				start++;
// 				end = nums.size();
// 			}
// 		}
        
// 		cur++;
// 	}
   
//     return totalCount;
// }
    
// Not sure what is wrong with my code, when I test the individual test case, it passes. But when I submit, the same test case fails. This seems like a bus with leetcode.
    
        int triangleNumber(vector<int>& nums) {
        vector<int> snums(nums);
        sort(snums.begin(), snums.end());
        int count = 0;
        for ( int n = nums.size(), k = n - 1; k > 1; --k ) {
            int i = 0, j = k - 1;
            while ( i < j ) {
                // any value x between i...j will satisfy snums[x] + snums[j] > snums[k]
                // and because snums[k] > snums[j] > snums[x] >= 0, they will always satisfy
                // snums[k] + snums[x] > snums[j] and snums[k] + snums[j] > snums[x]
                if ( snums[i] + snums[j] > snums[k] )
                    count += --j - i + 1;
                else
                    ++i;
            }
        }
        return count;
    }
};
