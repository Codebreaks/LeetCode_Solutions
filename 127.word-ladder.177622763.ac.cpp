/*
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (21.22%)
 * Total Accepted:    193K
 * Total Submissions: 909.8K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: 0
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
    
public:
    
int getDistance(string a, string b)
{
	int dist = 0;

	for (int i = 0; i < b.size(); i++)
		if (a[i] != b[i]) dist++;

	return dist;
}

void getTobeVisited(string beginWord, queue<string>& tobevisited, vector<string>& wordList, vector<bool>& visited)
{
	for (int i = 0; i < wordList.size(); i++)
	{
		if (!visited[i] && (getDistance(beginWord, wordList[i]) == 1)) { tobevisited.push(wordList[i]); visited[i] = true; }
	}
		
}


int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	if (!wordList.size()) return 0;
    
	//wordList.push_back(endWord);
    
	int dist = 1;
    
	queue<string> tobevisited;
	vector<bool> visited(wordList.size(), false);
    
	getTobeVisited(beginWord, tobevisited, wordList, visited);
    
    int count = tobevisited.size();
    
    while (count)
    {
        while (count)
        {
            if (tobevisited.front().compare(endWord) == 0) 
            {
                // cout << "here\n";
                ++dist;
                return dist;
            }
                

            else
            { 
                // cout << tobevisited.front() << "\t";
                getTobeVisited(tobevisited.front(), tobevisited, wordList, visited);
                tobevisited.pop();
            }
            
            --count;
        }
        
        // cout << "\n";
        ++dist;
        count = tobevisited.size();
    }
    
    return 0;
        
}
    
};
