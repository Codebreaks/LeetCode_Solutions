/*
 * [876] Hand of Straights
 *
 * https://leetcode.com/problems/hand-of-straights/description/
 *
 * algorithms
 * Medium (44.63%)
 * Total Accepted:    8.6K
 * Total Submissions: 19.3K
 * Testcase Example:  '[1,2,3,6,2,3,4,7,8]\n3'
 *
 * Alice has a hand of cards, given as an array of integers.
 * 
 * Now she wants to rearrange the cards into groups so that each group is size
 * W, and consists of W consecutive cards.
 * 
 * Return true if and only if she can.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
 * Output: true
 * Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
 * 
 * Example 2:
 * 
 * 
 * Input: hand = [1,2,3,4,5], W = 4
 * Output: false
 * Explanation: Alice's hand can't be rearranged into groups of 4.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= hand.length <= 10000
 * 0 <= hand[i] <= 10^9
 * 1 <= W <= hand.length
 * 
 */
class Solution {
public:
        bool isNStraightHand(vector<int> hand, int W) {
        map<int, int> c;
        for (int i : hand) c[i]++;
        for (auto it : c)
            if (c[it.first] > 0)
                for (int i = W - 1; i >= 0; --i)
                    if ((c[it.first + i] -= c[it.first]) < 0)
                        return false;
        return true;
    }
    
//  bool isNStraightHand(vector<int>& hand, int W) 
//  {
// 	 map<int, int> numfreq;
// 	 for (int x : hand)
// 		 numfreq[x]++;
     
     

// 	 map<int, int>::iterator itr = numfreq.begin();
// 	 int remaining = hand.size();
//      int window = 0;
//      vector<int> last;
//      bool first = true;
     
// 	 while (true)
// 	 {
		 
//          itr = numfreq.begin();
//          first = true;
// 		 while (itr != numfreq.end())
// 		 {
// 			 if (itr->second > 0)
// 			 {
// 				 if(!first)
//                  {
//                     if(itr->second = last[last.size()-1]+1)
//                     {
//                          itr->second -= 1;
//                          last.push_back(itr->first);
//                          remaining --;
//                          ++window;
                         
//                     }
//                  }
//                  else
//                  {
//                          itr->second -= 1;
//                          last.push_back(itr->first);
//                          remaining --;
//                          ++window;
//                          first = false;
//                  }

                        

                 
// 				 if (window == W)
// 				 {
//                      if (remaining == 0) return true;
//                      window = 0;
// 					 break;
// 				 }
                 
//                  if (remaining < W) return false;
// 			 }
// 			 else
// 				 itr++;
// 		 }
// 	 }

//  }
    
};
