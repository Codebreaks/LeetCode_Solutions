/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (23.96%)
 * Total Accepted:    309.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int totalCnt = nums1.size() + nums2.size();
	int mediancnt = ceil(totalCnt / 2.0);
	vector<double> holder;

	int medIndex = 0;

	int curCount = 0;
	int odd = false;
	if (totalCnt & 1)  // odd
		odd = true;

	int first = 0;
	int second = 0;

	while ((first < nums1.size()) && (second < nums2.size()))
	{

		if (nums1[first] < nums2[second])
		{
			holder.push_back(double(nums1[first]));

			if (holder.size() >= mediancnt)
			{
				if (odd) return holder.back();
				if (!odd && (holder.size() == (mediancnt + 1)))
				{
					double a = holder.back();
					holder.pop_back();
					double b = holder.back();
					return (a + b) / 2;
				}
			}
			first++;
		}

		else
		{
			holder.push_back(double(nums2[second]));

			if (holder.size() >= mediancnt)
			{
				if (odd) return holder.back();
				if (!odd && (holder.size() == (mediancnt + 1)))
				{
					double a = holder.back();
					holder.pop_back();
					double b = holder.back();
					return (a + b) / 2;
				}
			}

			second++;
		}
	}
    
    
	if (first == nums1.size())
	{
		while (holder.size() < mediancnt )
		{
			holder.push_back(nums2[second++]);
			
		}
		if (odd)
		{
			return holder.back();
		}
		else
			return (holder.back() + nums2[second]) / 2;
	}

	else
		
		{
			while (holder.size() < mediancnt)
			{
				holder.push_back(nums1[first++]);

			}
			if (odd)
			{
				return holder.back();
			}
			else
				return (holder.back() + nums1[first]) / 2;
		}

}
    
    
};
