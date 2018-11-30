/*
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (28.19%)
 * Total Accepted:    74.9K
 * Total Submissions: 265.6K
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 * 
 * Example 1:
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 * 
 */
class Solution {
public:
int thirdMax(vector<int>& nums) 
{
	int k = 3;

	priority_queue<int, std::vector<int>, std::greater<int> > maxkelemetns;
	
    int maxele = INT_MIN;
    
    sort(nums.begin(), nums.end());

    int lastele = -1; 
    
	for (int a : nums)
	{
		if(a == lastele) continue;
        
        lastele = a;
        maxele = max(a, maxele);

		if (maxkelemetns.size() < k)
		{
			maxkelemetns.push(a);
		}
		else
		{
			if (a > maxkelemetns.top())
			{
				maxkelemetns.pop();
				maxkelemetns.push(a);
			}
		}
	}

	return maxkelemetns.size() > 2 ? maxkelemetns.top(): maxele;
}
    
};
