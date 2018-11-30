/*
 * [830] Largest Triangle Area
 *
 * https://leetcode.com/problems/largest-triangle-area/description/
 *
 * algorithms
 * Easy (53.38%)
 * Total Accepted:    9.2K
 * Total Submissions: 17.2K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[0,2],[2,0]]'
 *
 * You have a list of points in the plane. Return the area of the largest
 * triangle that can be formed by any 3 of the points.
 * 
 * 
 * Example:
 * Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
 * Output: 2
 * Explanation: 
 * The five points are show in the figure below. The red triangle is the
 * largest.
 * 
 * 
 * 
 * 
 * Notes: 
 * 
 * 
 * 3 <= points.length <= 50.
 * No points will be duplicated.
 * -50 <= points[i][j] <= 50.
 * Answers within 10^-6 of the true value will be accepted as correct.
 * 
 * 
 * 
 */
class Solution {
public:
    double getDist(vector<int> pt)
{
	double ans =  sqrt(pow(pt[0], 2.0) + (pt[1], 2.0));
        cout << "ans" << ans << endl;
        return ans;
}
    
double largestTriangleArea(vector<vector<int>>& points) {

	vector<int> xmaxPoint;
	vector<int> ymaxPoint;
	vector<int> maxOrigin;
	int xMax = 0;
	int yMax = 0;
	double distOrigin = INT_MAX;

	for (int i = 0; i < points.size(); i++)
	{
		if (points[i][0] > xMax)
		{
			xMax = points[i][0];
			xmaxPoint.clear();
			xmaxPoint.push_back(points[i][0]);
			xmaxPoint.push_back(points[i][1]);
		}


		if (points[i][1] > yMax)
		{
			yMax = points[i][1];
			ymaxPoint.clear();
			ymaxPoint.push_back(points[i][0]);
			ymaxPoint.push_back(points[i][1]);
		}

		if (getDist(points[i]) < distOrigin)
		{
			maxOrigin.clear();
            
            distOrigin = getDist(points[i]);
            cout << "DIst" << distOrigin << endl;
			maxOrigin.push_back(points[i][0]);
			maxOrigin.push_back(points[i][1]);

		}
	}
    cout << maxOrigin[0] << maxOrigin[1];
    
	double a = xmaxPoint[0] * (ymaxPoint[1] - maxOrigin[1]);
	double b = ymaxPoint[0] * (maxOrigin[1] - xmaxPoint[1]);
	double c = maxOrigin[0] * (xmaxPoint[1] - ymaxPoint[1]);
	return abs((a + b + c) / 2);

}
};
