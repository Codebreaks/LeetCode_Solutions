/*
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (34.97%)
 * Total Accepted:    151.6K
 * Total Submissions: 433.4K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */
class Solution {
public:

bool canFinish2(int node, vector<bool>& visited, vector<bool>& recursion, vector<vector<int>>& dependency)
{
	////if (visited[node] == false)
	//{
		visited[node] = true;
		recursion[node] = true;

		for (int i = 0; i < dependency[node].size(); i++)
		{
			if (visited[dependency[node][i]] == false && canFinish2(dependency[node][i], visited, recursion, dependency))
				return true;

			else if (recursion[dependency[node][i]] == true) return true;
		}
	//}
	recursion[node] = false;
	return false;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	
	vector<vector<int>> dependency(numCourses);
	vector<pair<int, int>>::iterator itr = prerequisites.begin();


	while (itr != prerequisites.end())
	{
		dependency[itr->first].push_back(itr->second);
		itr++;
	}
	for (int i = 0; i < numCourses; i++)
	{
		vector<bool> visited(numCourses, false);
		vector<bool> recursion(numCourses, false);
		if (canFinish2( i, visited, recursion, dependency)) return false;
	}
	return true;
}
    
};
