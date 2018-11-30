/*
 * [253] Meeting Rooms II
 *
 * https://leetcode.com/problems/meeting-rooms-ii/description/
 *
 * algorithms
 * Medium (40.53%)
 * Total Accepted:    98.8K
 * Total Submissions: 243.8K
 * Testcase Example:  '[[0,30],[5,10],[15,20]]'
 *
 * Given an array of meeting time intervals consisting of start and end times
 * [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms
 * required.
 * 
 * Example 1:
 * 
 * 
 * Input: [[0, 30],[5, 10],[15, 20]]
 * Output: 2
 * 
 * Example 2:
 * 
 * 
 * Input: [[7,10],[2,4]]
 * Output: 1
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct test
{
  bool operator()(const int& a, const int& b)
  {
      return a > b;
  }
    
};

class Solution {
public:
    


int minMeetingRooms(vector<Interval>& intervals) {

	if (intervals.empty()) return 0;

	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
    
    priority_queue<int, vector<int>, test> endng;
    
    endng.push(intervals[0].end);
    
	int rooms = 0;
	rooms++;
	int time = 0;

	for (int i = 1; i < intervals.size(); i++)
	{
        if(endng.top() <= intervals[i].start)
        {
            endng.pop();
        }
		else
		{
			rooms++;
		}
        endng.push(intervals[i].end);

	}
	return rooms;
}
};
