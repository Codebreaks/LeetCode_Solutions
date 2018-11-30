/*
 * [170] Two Sum III - Data structure design
 *
 * https://leetcode.com/problems/two-sum-iii-data-structure-design/description/
 *
 * algorithms
 * Easy (28.29%)
 * Total Accepted:    46.8K
 * Total Submissions: 165.6K
 * Testcase Example:  '["TwoSum","add","add","add","find","find"]\n[[],[1],[3],[5],[4],[7]]'
 *
 * Design and implement a TwoSum class. It should support the following
 * operations: add and find.
 * 
 * add - Add the number to an internal data structure.
 * find - Find if there exists any pair of numbers which sum is equal to the
 * value.
 * 
 * Example 1:
 * 
 * 
 * add(1); add(3); add(5);
 * find(4) -> true
 * find(7) -> false
 * 
 * 
 * Example 2:
 * 
 * 
 * add(3); add(1); add(2);
 * find(3) -> true
 * find(6) -> false
 * 
 */
class TwoSum {
public:
	/** Initialize your data structure here. */
	unordered_set<int> seen;
	unordered_set<int> optimize;
	vector<int> holder;
	TwoSum() {

	}

	/** Add the number to an internal data structure.. */
	void add(int number) {
		holder.push_back(number);
	}

	/** Find if there exists any pair of numbers which sum is equal to the value. */
	bool find(int value) 
	{
		if (optimize.count(value)) return true;

		for (int a : holder)
		{
			if (seen.count(value - a))
			{
				seen.clear();
				optimize.insert(value);
				return true;
			}
			else
				seen.insert(a);
		}
		seen.clear();
		return false;
	}
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
