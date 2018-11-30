/*
 * [727] Minimum Window Subsequence
 *
 * https://leetcode.com/problems/minimum-window-subsequence/description/
 *
 * algorithms
 * Hard (33.45%)
 * Total Accepted:    9.5K
 * Total Submissions: 28.4K
 * Testcase Example:  '"abcdebdde"\n"bde"'
 *
 * Given strings S and T, find the minimum (contiguous) substring W of S, so
 * that T is a subsequence of W.
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "". If there are multiple such minimum-length windows, return
 * the one with the left-most starting index.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * S = "abcdebdde", T = "bde"
 * Output: "bcde"
 * Explanation: 
 * "bcde" is the answer because it occurs before "bdde" which has the same
 * length.
 * "deb" is not a smaller window because the elements of T in the window must
 * occur in order.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All the strings in the input will only contain lowercase letters.
 * The length of S will be in the range [1, 20000].
 * The length of T will be in the range [1, 100].
 * 
 * 
 * 
 * 
 */
// class Solution {
// public:
    
//     map<char, int> positions;
        
//     bool isFit(string s, int start, int end)
//     {
//        cout << "\n";
//         int index = 0;
        
//         while(start <= end)
//         {
//             // cout << s[start] << "\t" ;
//             if(positions.find(s[start]) != positions.end())
//             {
//                if (positions[s[start]] != index++) return false; 
//             }
//                 start++;  
//         }
//         return true;
           
     
//     }
    
//     string minWindow(string s, string t) {
        
        
//         	 if (!s.size() || !t.size()) return "";
     
// 	 map<char, int> tmdict;
// 	 map<char, int> winddict;
//         int i = 0;

// 	 for (char x : t)
//      {
//          tmdict[x] += 1;
//          positions[x] = i++;
//      }
		 

// 	 int required = tmdict.size();
// 	 int formed = 0;
// 	 int a[3] = { -1,0,0 };
// 	 int l = a[1];
// 	 int r = a[2];
// 	 bool setleft = true;

// 	 while (r < s.size())
// 	 {
// 		 char c = s[r];
         
// 		 winddict[c] += 1;

// 		 if (tmdict.find(c) != tmdict.end() && tmdict[c] == winddict[c]) formed++;
         
//          // cout << c << "\t" <<winddict[c] << "  "<<tmdict[c] << " " << formed << endl;

// 		 while(formed == required && (l <= r))
// 		 {
// 			 // cout << "****";
//              if ((a[0] == -1 || a[0] > (r - l + 1)) && isFit(s,l,r))
// 			 {
// 				 cout << "Hello";
                 
//                  a[0] = (r - l + 1);               
// 				 a[1] = l;
// 				 a[2] = r;
// 			 }

// 			 char p = s[l];
// 			 winddict[p] -= 1;
//              // cout << p <<endl;
             
// 			 if (tmdict.find(p) != tmdict.end() && winddict[p] < tmdict[p])
// 			 {
// 				 formed--;
// 			 }
             
// 			 l++;
// 		 }
         
// 		 r++;
// 	 }

// 	 return a[0] == -1 ? "" : s.substr(a[1], (a[2] - a[1] + 1));

//     }
    
    
// };


class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < m; i++) 
            if (S[i] == T[0]) dp[0][i] = i;
        for (int j = 1; j < n; j++) {
            int k = -1;
            for (int i = 0; i < m; i++) {
                if (k != -1 && S[i] == T[j]) dp[j][i] = k;
                if (dp[j-1][i] != -1) k = dp[j-1][i];
            }
        }
        int st = -1, len = INT_MAX;
        for (int i = 0; i < m; i++) {
            if (dp[n-1][i] != -1 && i-dp[n-1][i]+1 < len) {
                st = dp[n-1][i];
                len = i-dp[n-1][i]+1;
            }    
        }
        return st == -1? "":S.substr(st, len);
    }
};
