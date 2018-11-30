/*
 * [551] Student Attendance Record I
 *
 * https://leetcode.com/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (44.93%)
 * Total Accepted:    40.2K
 * Total Submissions: 89.4K
 * Testcase Example:  '"PPALLP"'
 *
 * You are given a string representing an attendance record for a student. The
 * record only contains the following three characters:
 * 
 * 
 * 
 * 'A' : Absent. 
 * 'L' : Late.
 * ⁠'P' : Present. 
 * 
 * 
 * 
 * 
 * A student could be rewarded if his attendance record doesn't contain more
 * than one 'A' (absent) or more than two continuous 'L' (late).    
 * 
 * You need to return whether the student could be rewarded according to his
 * attendance record.
 * 
 * Example 1:
 * 
 * Input: "PPALLP"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "PPALLL"
 * Output: False
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
bool checkRecord(string s) {
	if (!s.size()) return true;
	int a = false;
	int l = false;
	char last = 'k';
    char lastlast = 'm';

	for (char c : s)
	{
		if (c == 'P') 
        {
		    lastlast = last;
            last = 'P';
			continue;
		}
		else if (c == 'A') {
			if (a) return false;
			else a = true;
            
            lastlast = last;
			last = 'A';

		}
		else
		{
			if (last == 'L' && lastlast == 'L' ) return false;
			lastlast = last;
			last = 'L';
		}
	}
	return true;
}
};
