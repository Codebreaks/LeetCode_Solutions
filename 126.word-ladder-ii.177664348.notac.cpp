/*
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (15.73%)
 * Total Accepted:    94.7K
 * Total Submissions: 602K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 * 
 * 
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return an empty list if there is no such transformation sequence.
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
 * Output:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
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
 * Output: []
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
    
// int getDistance(string a, string b)
// {
// 	int dist = 0;

// 	for (int i = 0; i < b.size(); i++)
// 		if (a[i] != b[i]) dist++;

// 	return dist;
// }
    
// void getTobeVisited(string beginWord, map<string, vector<string>>& tobevisited, vector<string>& wordList)
// {
// 	for (int i = 0; i < wordList.size(); i++)
// 	{
// 		if(getDistance(beginWord, wordList[i]) == 1)
// 			{ tobevisited[beginWord].push_back(wordList[i]); }
// 	}
// }

// void getPaths(vector<vector<string>>& ans, map<string, vector<string>>& neighbor, map<string, bool>& visited, string endWord, string currentWord, vector<string>& path, vector<string>& wordList)
// {
// 	visited[currentWord] = true;
// 	path.push_back(currentWord);
//     cout << currentWord;

// 	if (currentWord.compare(endWord) == 0)
// 	{
// 		ans.push_back(path);
// 		return;
	
// 	}

// 	if(neighbor.find(currentWord) == neighbor.end())
// 		getTobeVisited(currentWord, neighbor, wordList);

//     for (auto x : neighbor[currentWord])
//     {
//         if(visited[x] == false)
//         {
//             getPaths(ans, neighbor, visited, endWord, x, path, wordList);
//             visited[x] = false;
//             path.pop_back();
//         }
//     }
// }

// vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
// {
// 	vector<vector<string>> ans;
// 	map<string, vector<string>> neighbor;
// 	map<string, bool> visited;

// 	if (!wordList.size()) return ans;
	

// 	getTobeVisited(beginWord, neighbor, wordList);

// 	for (auto x : neighbor[beginWord])
// 	{
// 		vector<string> currentPath;
// 		currentPath.push_back(beginWord);
//         visited[x] = true;
// 		getPaths(ans, neighbor, visited, endWord, x, currentPath, wordList);
//         currentPath.clear();
//         cout << endl;
// 	}
// 	return ans;
// }
    
    public:
    int ladderLength(std::string beginWord, std::string endWord, std::unordered_set<std::string> &dict) {
		if (beginWord == endWord)
			return 1;
        std::unordered_set<std::string> words1, words2;
		words1.insert(beginWord);
		words2.insert(endWord);
        dict.erase(beginWord);
        dict.erase(endWord);
        return ladderLengthHelper(words1, words2, dict, 1);
    }

private:
    int ladderLengthHelper(std::unordered_set<std::string> &words1, std::unordered_set<std::string> &words2, std::unordered_set<std::string> &dict, int level) {
		if (words1.empty())
            return 0;
		if (words1.size() > words2.size())
			return ladderLengthHelper(words2, words1, dict, level);
        std::unordered_set<std::string> words3;
        for (auto it = words1.begin(); it != words1.end(); ++it) {
			std::string word = *it;
			for (auto ch = word.begin(); ch != word.end(); ++ch) {
				char tmp = *ch;
                for (*ch = 'a'; *ch <= 'z'; ++(*ch))
					if (*ch != tmp)
						if (words2.find(word) != words2.end())
                            return level + 1;
						else if (dict.find(word) != dict.end()) {
                            dict.erase(word);
                            words3.insert(word);
                        }
				*ch = tmp;
            }
        }
        return ladderLengthHelper(words2, words3, dict, level + 1);
    }
    
    
    
    
};
