/*
 * [165] Compare Version Numbers
 *
 * https://leetcode.com/problems/compare-version-numbers/description/
 *
 * algorithms
 * Medium (21.60%)
 * Total Accepted:    112.3K
 * Total Submissions: 519.9K
 * Testcase Example:  '"0.1"\n"1.1"'
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1; if version1 < version2 return -1;otherwise
 * return 0.
 * 
 * You may assume that the version strings are non-empty and contain only
 * digits and the . character.
 * The . character does not represent a decimal point and is used to separate
 * number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it
 * is the fifth second-level revision of the second first-level revision.
 * 
 * Example 1:
 * 
 * 
 * Input: version1 = "0.1", version2 = "1.1"
 * Output: -1
 * 
 * Example 2:
 * 
 * 
 * Input: version1 = "1.0.1", version2 = "1"
 * Output: 1
 * 
 * Example 3:
 * 
 * 
 * Input: version1 = "7.5.2.4", version2 = "7.5.3"
 * Output: -1
 * 
 */
class Solution {
public:
    

int compareVersion(string version1, string version2) {

		
    	int a = version1.size();
		int b = version2.size();
            // Remove trailing
		int i = 0;
    
        if(a != b){
    

		while (version1[i] == '0' && (version1.find('.') == std::string::npos))
		{
			i++;
		}

		version1 = version1.substr(i);
            
                
		// Remove trailing
		i = 0;
		while (version2[i] == '0' && (version2.find('.') == std::string::npos))
		{
			i++;
		}

		version2 = version2.substr(i);
        
        }
    
    a = version1.size();
    b = version2.size();

		if (a>b)
		{
			while (b!=a)
			{
				version2 += ".0";
				b = version2.size();
			}
		}
		else if (b>a)
		{
			while (a != b)
			{
				version1 += ".0";
				a = version1.size();
			}
		}

		for (i = 0; i < version1.size(); i++)
		{
			if (version1[i] == version2[i]) continue;

			if (version1[i] > version2[i]) return 1;

			else return -1;
		}

		return 0;
}
    
};
