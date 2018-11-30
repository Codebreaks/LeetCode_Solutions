/*
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (32.68%)
 * Total Accepted:    204K
 * Total Submissions: 624.3K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
class Solution {
public:
int threeSumClosest(vector<int>& nums, int target) {

	vector<vector<int>> ans;
	int sum = 0;
	int closestsum = 0;
    int lastgap = (INT_MAX - 1);

	int maxsubsets = pow(2, nums.size());
	for (int i = 0; i < maxsubsets; i++)
	{
		vector<int> current;
		int j = 1;
		int count = nums.size();
		int index = 0;

		while (count)
		{
			if (i & j)
			{
				current.push_back(nums[index]);
				sum += nums[index];
			}

			j = j << 1;
			--count;
			++index;
		}
        
               
		if (current.size() == 3)
		{
			int t = target;
			int steps = 0;
            
            
			if (sum > target)
			{
				while (t != sum) { steps++; t++; }
			}
			else
			{
				while (t != sum) { steps++; t--; }
			}
            
            
            
            if(lastgap > steps)
            {
             
                closestsum = sum;
                lastgap = steps;
            }
            
            cout << sum << "\t" << steps << "\t" << closestsum << endl;
		}
		sum = 0;
	}
	return closestsum;
}

};
