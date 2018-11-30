/*
 * [535] Encode and Decode TinyURL
 *
 * https://leetcode.com/problems/encode-and-decode-tinyurl/description/
 *
 * algorithms
 * Medium (74.56%)
 * Total Accepted:    54.9K
 * Total Submissions: 73.6K
 * Testcase Example:  '"https://leetcode.com/problems/design-tinyurl"'
 *
 * Note: This is a companion problem to the System Design problem: Design
 * TinyURL.
 * 
 * TinyURL is a URL shortening service where you enter a URL such as
 * https://leetcode.com/problems/design-tinyurl and it returns a short URL such
 * as http://tinyurl.com/4e9iAk.
 * 
 * Design the encode and decode methods for the TinyURL service. There is no
 * restriction on how your encode/decode algorithm should work. You just need
 * to ensure that a URL can be encoded to a tiny URL and the tiny URL can be
 * decoded to the original URL.
 * 
 */
class Solution {
public:
	unordered_map<string, string> shortner;
	string base = "www.tinyurl.com/";
	int counter = 0;

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) 
	{
		string val = base + to_string(counter);
		shortner[to_string(counter)] = longUrl;
		counter++;
		return val;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		int pos = shortUrl.find("/");
		pos++;
		string key = shortUrl.substr(pos);
		return shortner[key];
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
