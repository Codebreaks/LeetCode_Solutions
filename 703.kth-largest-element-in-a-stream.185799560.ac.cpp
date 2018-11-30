/*
 * [789] Kth Largest Element in a Stream
 *
 * https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
 *
 * algorithms
 * Easy (39.08%)
 * Total Accepted:    9.6K
 * Total Submissions: 24.6K
 * Testcase Example:  '["KthLargest","add","add","add","add","add"]\n[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]'
 *
 * Design a class to find the kth largest element in a stream. Note that it is
 * the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Your KthLargest class will have a constructor which accepts an integer k and
 * an integer array nums, which contains initial elements from the stream. For
 * each call to the method KthLargest.add, return the element representing the
 * kth largest element in the stream.
 * 
 * Example:
 * 
 * 
 * int k = 3;
 * int[] arr = [4,5,8,2];
 * KthLargest kthLargest = new KthLargest(3, arr);
 * kthLargest.add(3);   // returns 4
 * kthLargest.add(5);   // returns 5
 * kthLargest.add(10);  // returns 5
 * kthLargest.add(9);   // returns 8
 * kthLargest.add(4);   // returns 8
 * 
 * 
 * Note: 
 * You may assume that nums' length ≥ k-1 and k ≥ 1.
 * 
 */
class KthLargest {
public:
    
    struct comparemy
{
	bool operator()(const int& a, const int& b)
	{
		return a > b;
	}
};
    

priority_queue<int, vector<int>, comparemy> sortedList;

int kthelement = -1;    
    


KthLargest(int k, vector<int> nums) 
{
	kthelement = k;

	for (int i = 0; i < nums.size(); i++)
	{
		if (sortedList.size() < k) sortedList.push(nums[i]);
		else
		{
			if (nums[i] > sortedList.top())
			{
				sortedList.pop();
				sortedList.push(nums[i]);
			}
		}
	}

}

int add(int val) 
{
	if (sortedList.size() < kthelement) sortedList.push(val);
	else
	{
		if (val > sortedList.top())
		{
			sortedList.pop();
			sortedList.push(val);
		}
	}
	return sortedList.top();
}
    
    
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
