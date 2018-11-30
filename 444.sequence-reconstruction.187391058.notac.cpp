/*
 * [444] Sequence Reconstruction
 *
 * https://leetcode.com/problems/sequence-reconstruction/description/
 *
 * algorithms
 * Medium (19.63%)
 * Total Accepted:    13.4K
 * Total Submissions: 68.1K
 * Testcase Example:  '[1,2,3]\n[[1,2],[1,3]]'
 *
 * Check whether the original sequence org can be uniquely reconstructed from
 * the sequences in seqs. The org sequence is a permutation of the integers
 * from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest
 * common supersequence of the sequences in seqs (i.e., a shortest sequence so
 * that all sequences in seqs are subsequences of it). Determine whether there
 * is only one sequence that can be reconstructed from seqs and it is the org
 * sequence.
 * 
 * Example 1:
 * 
 * Input:
 * org: [1,2,3], seqs: [[1,2],[1,3]]
 * 
 * Output:
 * false
 * 
 * Explanation:
 * [1,2,3] is not the only one sequence that can be reconstructed, because
 * [1,3,2] is also a valid sequence that can be reconstructed.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * org: [1,2,3], seqs: [[1,2]]
 * 
 * Output:
 * false
 * 
 * Explanation:
 * The reconstructed sequence can only be [1,2].
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:
 * org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]
 * 
 * Output:
 * true
 * 
 * Explanation:
 * The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original
 * sequence [1,2,3].
 * 
 * 
 * 
 * Example 4:
 * 
 * Input:
 * org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]
 * 
 * Output:
 * true
 * 
 * 
 * 
 * 
 * UPDATE (2017/1/8):
 * The seqs parameter had been changed to a list of list of strings (instead of
 * a 2d array of strings). Please reload the code definition to get the latest
 * changes.
 * 
 */
class Solution {
public:
map<int, set<int>> children;
map<int, int> indegree;

bool getUniqueTopologial(vector<int>& org, map<int, bool>& visited, vector<int>& res, vector<vector<int>>& finalResult)
{

    for (auto x: indegree)
	{
		if (x.second == 0 && visited.find(x.first)->second == false)
		{
			for (auto c : children.find(x.first)->second)
				indegree.find(c)->second = indegree.find(c)->second - 1;

			res.push_back(x.first);
			visited.find(x.first)->second = true;

			if (getUniqueTopologial(org, visited, res, finalResult) == false) return false;

			visited.find(x.first)->second = false;
			res.erase(res.end() - 1);

			for (auto c : children.find(x.first)->second)
				indegree.find(c)->second = indegree.find(c)->second + 1;
 
		}
	}

	if (org.size() == res.size() )
	{
		
        finalResult.push_back(res);
        if(finalResult.size() > 1) return false;

	}
   return true;
}
    
bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) 
{
	map<int, bool> visited;
	vector<int> res;
	vector<vector<int>> finalResult;
    
    if(!seqs.size()) return false;
    
    bool indeg = false;

	for (auto x : org)
	{ 
		indegree[x] = 0;
		visited[x] = false;
	}

	for (int i = 0; i < seqs.size(); i++)
	{
		for (int j = 1; j < seqs[i].size(); j++)
		{
			if (children[seqs[i][j - 1]].insert(seqs[i][j]).second)
			{
				indegree.find(seqs[i][j])->second += 1;
                indeg = true;
			}
		}
        if(seqs[i].size() == 0) return false;
	}
    
    

    if ( getUniqueTopologial(org, visited, res, finalResult) == true)
    {
        return (finalResult.size() == 1);
    }
    else
        return false;
        
}
    
};
