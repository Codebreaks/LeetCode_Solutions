/*
 * [244] Shortest Word Distance II
 *
 * https://leetcode.com/problems/shortest-word-distance-ii/description/
 *
 * algorithms
 * Medium (43.92%)
 * Total Accepted:    38.3K
 * Total Submissions: 87.2K
 * Testcase Example:  '["WordDistance","shortest","shortest"]\n[[["practice","makes","perfect","coding","makes"]],["coding","practice"],["makes","coding"]]'
 *
 * Design a class which receives a list of words in the constructor, and
 * implements a method that takes two words word1 and word2 and return the
 * shortest distance between these two words in the list. Your method will be
 * called repeatedly many times with different parameters. 
 * 
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 * 
 * 
 * Input: word1 = “coding”, word2 = “practice”
 * Output: 3
 * 
 * 
 * 
 * Input: word1 = "makes", word2 = "coding"
 * Output: 1
 * 
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are
 * both in the list.
 * 
 */
class WordDistance {
    
public:
    WordDistance(vector<string> words) {
        for(int i=0; i<words.size(); ++i){
            mp[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>& x = mp[word1] , &y = mp[word2];

        int i=0, j=0;
        int ret = INT_MAX;
        while(i<x.size() && j<y.size()){
            ret = min(ret, abs(x[i]-y[j]));
            if(x[i] > y[j])
                ++j;
            else if(x[i] < y[j])
                ++i;
        }
        
        return ret;
    }
    
private:
    unordered_map<string, vector<int>> mp;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
