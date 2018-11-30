/*
 * [813] All Paths From Source to Target
 *
 * https://leetcode.com/problems/all-paths-from-source-to-target/description/
 *
 * algorithms
 * Medium (67.34%)
 * Total Accepted:    14.1K
 * Total Submissions: 20.9K
 * Testcase Example:  '[[1,2],[3],[3],[]]'
 *
 * Given a directed, acyclic graph of N nodes.  Find all possible paths from
 * node 0 to node N-1, and return them in any order.
 * 
 * The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.
 * graph[i] is a list of all nodes j for which the edge (i, j) exists.
 * 
 * 
 * Example:
 * Input: [[1,2], [3], [3], []] 
 * Output: [[0,1,3],[0,2,3]] 
 * Explanation: The graph looks like this:
 * 0--->1
 * |    |
 * v    v
 * 2--->3
 * There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the graph will be in the range [2, 15].
 * You can print different paths in any order, but you should keep the order of
 * nodes inside one path.
 * 
 * 
 */
class Solution {
public:

void getPaths(vector<vector<int>>& graph, int node, vector<int> path, vector<bool> visited, int maxNode, vector<vector<int>>& ans)
{
	if (node == maxNode) {
        // cout <<"Here"<<endl;
        ans.push_back(path);
    }
    
	else
	{
		for (int x : graph[node])
        {
			// cout << "inside " << x << "  "<< visited[x] << endl;
            
            
            if (visited[x] == false)
			{
				// cout<<"** "<<x<<endl;
                visited[x] = true;
				path.push_back(x);

				getPaths(graph, x, path, visited, maxNode, ans);
				path.pop_back();
                visited[x] = false;
			}
        }
		
	}
}


vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

	vector<vector<int>> ans;
	int n = graph.size();
	if (!n) return ans;
	vector<bool> visited(n, false);

	vector<int> path;
	for (int x : graph[0])
	{
		visited[0] = true;
		path.push_back(0);
        
        visited[x] = true;
        path.push_back(x);
        
        cout << x << endl;
        
		getPaths(graph, x, path, visited, n-1, ans);

		path.clear();
        for(int i=0; i<n; i++)
            visited[i] = false;
		
	}
	return ans;
}

    
    
    
    
    
    
    
    
    
    
};
