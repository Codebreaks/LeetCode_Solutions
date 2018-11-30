/*
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (39.39%)
 * Total Accepted:    72.6K
 * Total Submissions: 184.4K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given an unsorted array return whether an increasing subsequence of length 3
 * exists or not in the array.
 * 
 * Formally the function should:
 * 
 * Return true if there exists i, j, k 
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return
 * false.
 * 
 * Note: Your algorithm should run in O(n) time complexity and O(1) space
 * complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [5,4,3,2,1]
 * Output: false
 * 
 * 
 * 
 * 
 */
class mytype
{
    public:
    int a;
    mytype();
    mytype(int k) { a = k;}
     
    bool operator < (const mytype& rhs) const
    {
        return a > rhs.a;
    }
    
};

class Solution {
public:
    
// bool increasingTriplet(vector<int>& nums) {
// 	if (nums.size() < 3) return false;

// 	priority_queue<mytype> myqueue;
    
// 	int count = 0;
    
//     int last = INT_MIN;

// 	for (int a : nums)
// 	{
// 		mytype p(a);
        
//         myqueue.push(p);
        
// 		if (a == myqueue.top().a)  count = 1;
		
//         else
// 		{
// 			count++;
// 			// if (count == 3) return true;
// 		}
//         cout << myqueue.top().a << "\t";

// 		if (myqueue.size() == 3) myqueue.pop();
// 	}
// 	return false;
// }
    
    
    bool increasingTriplet(vector<int>& nums) {
	if (nums.size() < 3) return false;

	int c1 = INT_MAX, c2 = INT_MAX;

	for (int a : nums)
	{
		if (a <= c1)
		{
			c1 = a;
		}
		else if (a <= c2)
		{
			c2 = a;
		}
		else
		{
			return true;
		}
	}
	return false;
}
    
    
};
