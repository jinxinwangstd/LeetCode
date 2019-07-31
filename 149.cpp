#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class Solution
{
public:
	int maxPoints(vector< vector<int> >& points)
	{
		int ret = 0;
		int num = points.size();
		if (num < 3)
			return num;
		unordered_map<double, int> lines;
		for (int i = 0; i < num; ++i)
		{
			lines.clear();
			int horizontal_points = 1;
			int count = 1;
			int duplicates = -1;
			for (int j = 0; j < num; ++j)
			{
				int x1 = points[i][0];
				int x2 = points[j][0];
				int y1 = points[i][1];
				int y2 = points[j][1];
				if (x1 == x2 && y1 == y2)
					duplicates++;
				else if (y1 == y2)
					horizontal_points++;
				else
				{
					double slope = (double) (x1 - x2) / (y1 - y2);
					lines[slope] = lines[slope] ? lines[slope] + 1 : 2;
					count = max(count, lines[slope]);
				}
			}
			ret = max(ret, duplicates + max(count, horizontal_points));
		}
		return ret;
	}
};
