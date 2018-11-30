/*
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (44.18%)
 * Total Accepted:    49.7K
 * Total Submissions: 112.5K
 * Testcase Example:  '[ ["a","b"],["b","c"] ]\n[2.0,3.0]\n[ ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]'
 *
 * 
 * Equations are given in the format A / B = k, where  A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 * 
 * Example:
 * Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e
 * = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 * 
 * 
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 * 
 * 
 * According to the example above:
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ]. 
 * 
 * 
 * 
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 * 
 */
class Solution {
public:
 pair<bool, double> search(string& a, string& b, unordered_set<string>& visited, double val, unordered_map<string, vector<pair<string, double>>>& children)
 {
		 visited.insert(a);                                                                  // mark a as visited
		 for (auto p : children[a])
		 {
			 if (visited.count(p.first) == 0)
			 {
				 double temp = val * p.second;
				 if (b.compare(p.first) == 0) return make_pair(true, temp);
				 auto result = search(p.first, b, visited, temp, children);
				 if (result.first) return result;
			 }
		 }

	 return make_pair(false, -1.0);
 }

 vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries)
 {
	 unordered_map<string, vector<pair<string, double>>> children;
	 vector<double> ans;

	 for (int i = 0; i < equations.size(); i++)
	 {
		 children[equations[i].first].push_back(make_pair(equations[i].second,values[i]));
		 children[equations[i].second].push_back(make_pair(equations[i].first, 1.0/values[i]));
	 }
	
	 for (auto p: queries)
	 {
		 unordered_set<string> visited;
		 ans.push_back( (p.first == p.second && children.find(p.first) != children.end()) ? 1.0 : search(p.first, p.second, visited, 1.0, children).second);
	 }
     return ans;
}
};
