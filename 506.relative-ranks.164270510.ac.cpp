/*
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (47.16%)
 * Total Accepted:    35.3K
 * Total Submissions: 74.8K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * 
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so
 * they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two
 * athletes, you just need to output their relative ranks according to their
 * scores.
 * 
 * 
 * 
 * Note:
 * 
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 * 
 * 
 * 
 */
class Solution {
public:
    
vector<string> findRelativeRanks(vector<int>& nums) 
{
	vector<int> copy(nums);
	sort(copy.begin(), copy.end());
    	std::reverse(copy.begin(), copy.end());
	vector<string> ranks;

	for (int i = 0; i < nums.size(); i++)
	{
		int tofind = nums[i];

		for (int j = 0; j < copy.size(); j++)
		{
			if (tofind == copy[j])
			{
					switch (j)
					{
					case 0:
						ranks.push_back("Gold Medal");
						break;
					case 1:
						ranks.push_back("Silver Medal");
						break;
					case 2:
						ranks.push_back("Bronze Medal");
						break;
					default:
						ranks.push_back(to_string(j + 1));
						break;
				}
			}
		}
	}
    
    	return ranks;
}
                         
                         
};
