/*
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (33.38%)
 * Total Accepted:    277.8K
 * Total Submissions: 832.2K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
class Solution {
public:

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	int size = nums1.size();
	int num1Start = m - 1;
	int index = size - 1;
	int i = n-1;
    
    if(m == 0)
    {
        for( int j = 0; j < size; j++)
        {
            nums1[j] = nums2[j];
        }
        return;
    }
    
    if(i < 0) return;

	while (index >= 0 && i >= 0)
	{
		if (nums1[num1Start] > nums2[i])
		{
			nums1[index] = nums1[num1Start];
			num1Start--;
            
            if(num1Start < 0)
            {
                index--;
                while(index >= 0)    
                {
                  nums1[index] =  nums2[i];
                    index--;
                    i--;
                }
            }
		}
		else
		{
			nums1[index] = nums2[i];
			i--;
		}
		index--;
	}
}
};
