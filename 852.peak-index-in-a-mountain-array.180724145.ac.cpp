/*
 * [882] Peak Index in a Mountain Array
 *
 * https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
 *
 * algorithms
 * Easy (67.10%)
 * Total Accepted:    30.3K
 * Total Submissions: 45.1K
 * Testcase Example:  '[0,1,0]'
 *
 * Let's call an array A a mountain if the following properties hold:
 * 
 * 
 * A.length >= 3
 * There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] <
 * A[i] > A[i+1] > ... > A[A.length - 1]
 * 
 * 
 * Given an array that is definitely a mountain, return any i such that A[0] <
 * A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
 * 
 * Example 1:
 * 
 * 
 * Input: [0,1,0]
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,2,1,0]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * 
 * 3 <= A.length <= 10000
 * 0 <= A[i] <= 10^6
 * A is a mountain, as defined above.
 * 
 * 
 */
class Solution {
public:
int peakIndexInMountainArray2(vector<int>& a, int l, int h)
{
		int mid = l + (h - l) / 2;
		if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1]) return mid;
		if (a[mid] > a[mid - 1] && a[mid] < a[mid + 1]) return peakIndexInMountainArray2(a, mid+1, h);
		else
			return peakIndexInMountainArray2(a,l,mid-1); 
}

int peakIndexInMountainArray(vector<int>& A) 
{
	return peakIndexInMountainArray2(A, 0, A.size() - 1);
}
};
