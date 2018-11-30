/*
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (49.64%)
 * Total Accepted:    301K
 * Total Submissions: 606.4K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
class Solution {
public:
	int majorityElement(vector<int>& nums) {
        int length=nums.size();
       
	    int count = 1;
        
	    int Major = nums[0];
        
	    for (int i = 1; i<nums.size(); i++)
        {
	        if(count==0)
            {
                count = 1;
	            Major = nums[i];
            }
            else if (Major == nums[i])
		        count++;
	        else
		        count--;		
		}
        cout << count;
        return Major;
	}
};
