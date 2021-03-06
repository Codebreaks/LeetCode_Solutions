/*
 * [547] Friend Circles
 *
 * https://leetcode.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (50.27%)
 * Total Accepted:    52.6K
 * Total Submissions: 104.7K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * 
 * There are N students in a class. Some of them are friends, while some are
 * not. Their friendship is transitive in nature. For example, if A is a direct
 * friend of B, and B is a direct friend of C, then A is an indirect friend of
 * C. And we defined a friend circle is a group of students who are direct or
 * indirect friends.
 * 
 * 
 * 
 * Given a N*N matrix M representing the friend relationship between students
 * in the class. If M[i][j] = 1, then the ith and jth students are direct
 * friends with each other, otherwise not. And you have to output the total
 * number of friend circles among all the students.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * Output: 2
 * Explanation:The 0th and 1st students are direct friends, so they are in a
 * friend circle. The 2nd student himself is in a friend circle. So return
 * 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * Output: 1
 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd
 * students are direct friends, so the 0th and 2nd students are indirect
 * friends. All of them are in the same friend circle, so return 1.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * N is in range [1,200].
 * M[i][i] = 1 for all students.
 * If M[i][j] = 1, then M[j][i] = 1.
 * 
 * 
 */

// class Solution {
// public:
// void MarkNeighborsN(vector<vector<int>>& grid, int currow, int curcol, vector<bool>& visited, vector<bool>& visitedcol, int& iland)
//  {
// 	 int row = grid.size();
// 	 int col = row;

// 	 grid[currow][curcol] = -1;
    
//     if(visited[currow] == true || visitedcol[curcol] == true) {--iland; return;}
// 	 visited[currow] = true;
// 	 visitedcol[curcol] = true;

// 	 //left
// 	 if (((curcol - 1) >= 0) && (grid[currow][(curcol - 1)] == 1))
// 		 MarkNeighborsN(grid, currow, curcol - 1, visited, visitedcol,iland);

// 	 // right
// 	 if (((curcol + 1) < col) && (grid[currow][(curcol + 1)] == 1))
// 		 MarkNeighborsN(grid, currow, curcol + 1, visited, visitedcol,iland);

// 	 //Up
// 	 if (((currow - 1) >= 0) && (grid[currow - 1][curcol] == 1))
// 		 MarkNeighborsN(grid, currow - 1, curcol, visited, visitedcol,iland);

// 	 //Down
// 	 if (((currow + 1) < row) && (grid[currow + 1][curcol] == 1))
// 		 MarkNeighborsN(grid, currow + 1, curcol, visited, visitedcol,iland);

//  }

//  int findCircleNum(vector<vector<int>>& M) 
//  {
// 	 int row = M.size();
// 	 if (!row) return 0;
// 	 int col = row;
// 	 vector<bool> visited(row, false);
// 	 vector<bool> visitedcol(col, false);

	 
// 	 int iland = 0;

// 	 for (int currow = 0; currow < row; currow++)
// 	 {
// 		 for (int curcol = 0; curcol < col; curcol++)
// 		 {
// 			 if (M[currow][curcol] == 1)
// 			 {
// 				 if (visited[currow] == false && visitedcol[curcol] == false)
//                  {
//                      iland++;
//                      M[currow][curcol] = -1;
//                      visited[currow] = true;
//                      visitedcol[curcol] = true;
// 				     MarkNeighborsN(M, currow, curcol, visited, visitedcol, iland);
//                  }


// 			 }

// 		 }
// 	 }
// 	 return iland;
//  }
// };
    
    class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        vector<bool> visited(n, false);
        int groups = 0;
        for (int i = 0; i < visited.size(); i++) {
            groups += !visited[i] ? dfs(i, M, visited), 1 : 0;
        }
        return groups;
    }

private:
    void dfs(int i, vector<vector<int>>& M, vector<bool>& visited) {
        visited[i] = true;
        for (int j = 0; j < visited.size(); j++) {
            if (i != j && M[i][j] && !visited[j]) {
                dfs(j, M, visited);
            }
        }
    }
};

