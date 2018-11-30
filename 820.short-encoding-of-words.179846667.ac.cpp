/*
 * [839] Short Encoding of Words
 *
 * https://leetcode.com/problems/short-encoding-of-words/description/
 *
 * algorithms
 * Medium (43.96%)
 * Total Accepted:    5K
 * Total Submissions: 11.5K
 * Testcase Example:  '["time", "me", "bell"]'
 *
 * Given a list of words, we may encode it by writing a reference string S and
 * a list of indexes A.
 * 
 * For example, if the list of words is ["time", "me", "bell"], we can write it
 * as S = "time#bell#" and indexes = [0, 2, 5].
 * 
 * Then for each index, we will recover the word by reading from the reference
 * string from that index until we reach a "#" character.
 * 
 * What is the length of the shortest reference string S possible that encodes
 * the given words?
 * 
 * Example:
 * 
 * 
 * Input: words = ["time", "me", "bell"]
 * Output: 10
 * Explanation: S = "time#bell#" and indexes = [0, 2, 5].
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= words.length <= 2000.
 * 1 <= words[i].length <= 7.
 * Each word has only lowercase letters.
 * 
 * 
 */
class Solution {
public:
    
static bool compareByLength(const string& a, const string& b)
{
	return a.size() > b.size();
}


int minimumLengthEncoding(vector<string>& words2) {

    sort(words2.begin(), words2.end());
    
    vector<string> words;
    
    words.push_back(words2[0]);
    
    for(int i=1 ; i < words2.size(); i++)
    {
        if(words2[i-1].compare(words2[i]) != 0)
            words.push_back(words2[i]);
    }
    
    
	sort(words.begin(), words.end(), compareByLength);

	// for (string x : words)
	// 	cout << x << "\t";

	vector<string>::reverse_iterator itr;
	itr = words.rbegin();
	bool erased = false;

	while (itr != words.rend())
	{
		for (int i = 0; i < words.size(); i++)
		{
			if (words[i].size() > itr->size() && (words[i].compare((words[i].size() - itr->size()), itr->size(), *itr) == 0))
			{
				words.erase(--itr.base());
				erased = true;
				break;
			}

		}

		if (!erased)
			itr++;
		else
			itr = words.rbegin();
        
        erased = false;
	}
	int sizet = 0;
	for (string x : words)
		sizet += x.size() + 1;
	return sizet;
}    
};
