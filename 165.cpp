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
	int compareVersion(string version1, string version2)
	{
		queue<int> q1, q2;
		int start = 0, end = 0;
		string subpart;
		while ((end = version1.find(".", start)) != string::npos)
		{
			subpart = version1.substr(start, end - start);
			q1.push(stoi(subpart));
			start = end + 1;
		}
		subpart = version1.substr(start);
		q1.push(stoi(subpart));
		start = 0;
		while ((end = version2.find(".", start)) != string::npos)
		{
			subpart = version2.substr(start, end - start);
			q2.push(stoi(subpart));
			start = end + 1;
		}
		subpart = version2.substr(start);
		q2.push(stoi(subpart));
		while (!q1.empty() || !q2.empty())
		{
			int num1 = 0, num2 = 0;
			if (!q1.empty())
			{
				num1 = q1.front();
				q1.pop();
			}
			if (!q2.empty())
			{
				num2 = q2.front();
				q2.pop();
			}
			if (num1 > num2)
				return 1;
			if (num1 < num2)
				return -1;
		}
		return 0;
	}
};
