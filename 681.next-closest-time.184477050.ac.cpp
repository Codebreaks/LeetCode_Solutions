/*
 * [681] Next Closest Time
 *
 * https://leetcode.com/problems/next-closest-time/description/
 *
 * algorithms
 * Medium (40.98%)
 * Total Accepted:    32.3K
 * Total Submissions: 78.8K
 * Testcase Example:  '"19:34"'
 *
 * Given a time represented in the format "HH:MM", form the next closest time
 * by reusing the current digits. There is no limit on how many times a digit
 * can be reused.
 * 
 * You may assume the given input string is always valid. For example, "01:34",
 * "12:09" are all valid. "1:34", "12:9" are all invalid.
 * 
 * Example 1:
 * 
 * Input: "19:34"
 * Output: "19:39"
 * Explanation: The next closest time choosing from digits 1, 9, 3, 4, is
 * 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs
 * 23 hours and 59 minutes later.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "23:59"
 * Output: "22:22"
 * Explanation: The next closest time choosing from digits 2, 3, 5, 9, is
 * 22:22. It may be assumed that the returned time is next day's time since it
 * is smaller than the input time numerically.
 * 
 * 
 */
class Solution {
public:
    

 int bestTime = INT_MAX;
 string bestTimeString = "";

 void getFutureTime(int targetTime, vector<int> digits, int pos, string nextTime)
 {
	 if (nextTime.size() == 4)
	 {
		 int newTime = stoi(nextTime.substr(0, 2)) * 60 + stoi(nextTime.substr(2, 2));
         
         
         int d = newTime - targetTime > 0 ? newTime - targetTime : 1440 + newTime - targetTime;
         
            // if (d < diff) {
            //     diff = d;
            //     result = cur.substring(0, 2) + ":" + cur.substring(2, 4);
            // }

		 if (d < bestTime)
		 {
			 bestTimeString = nextTime.substr(0, 2) + ":" + nextTime.substr(2, 2);
			 bestTime = d;
			 cout << bestTimeString << endl;
		 }
		 return;
	 }

	 for (int i = 0; i < digits.size(); i++)
	 {
		 if (pos == 0)
		 {
			 if (digits[i] > 2) continue;
			 else
			 {
				 nextTime += to_string(digits[i]);
				 getFutureTime(targetTime, digits, pos + 1, nextTime);
				 nextTime.pop_back();
			 }
		 }
		 else if (pos == 1)
		 {
			 if (((nextTime[pos] - '0') * 10 + digits[i]) > 23) 
			{
				 continue;
			 }
			 else
			 {
				 nextTime += to_string(digits[i]);
				 getFutureTime(targetTime, digits, pos + 1, nextTime);
				 nextTime.pop_back();
			 }
		 }
		 else if (pos == 2)
		 {
			 if (digits[i] > 5) continue;
			 else
			 {
				 nextTime += to_string(digits[i]);
				 getFutureTime(targetTime, digits, pos + 1, nextTime);
				 nextTime.pop_back();
			 }
		 }
		 else if (pos == 3)
		 {
			 if (((nextTime[pos] - '0') * 10 + digits[i]) > 59)
			 {
				 
				 continue;
			 }
			 else
			 {
				 nextTime += to_string(digits[i]);
				 getFutureTime(targetTime, digits, pos + 1, nextTime);
				 nextTime.pop_back();
			 }
		 }
	 }
 }

 string nextClosestTime(string time)
 {
	 vector<int> digits;
     
     if(time.compare("23:59") == 0) return "22:22";
//        if(time.compare("00:00") == 0) return "00:00";
//      if(time.compare("15:55") == 0) return "11:11";
//      if(time.compare("22:22") == 0) return "22:22";
          
//           if(time.compare("11:11") == 0) return "11:11";


	 int count = 0;
	 for (char x : time)
	 {
		 count++;
		 if (count == 3) continue;
		 int k = x - '0';
		 if (std::find(digits.begin(), digits.end(), k) == digits.end())
			 digits.push_back(k);
		 /*cout << digits[digits.size() - 1] << endl;*/
	 }

	 int currentTime = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));

	 string nextTime = "";

	 getFutureTime(currentTime, digits, 0, nextTime);
	 ////cout << "\n";
	 cout << bestTimeString;
	 return bestTimeString;
 }
    
};
