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
	// This function simply a Unix path to the canonical path
	string simplifyPath(string path)
	{
		stack<string> hierarchy;	// we use a stack to maintain the depth in a directory tree
		size_t p = 0, end = 0;
		while (path[p] == '/')
			++p;
		while ((end = path.find('/', p)) != string::npos)
		{
			// find a directory name
			string name = path.substr(p, end - p);
			if (!name.empty())
			{
				if (name == "..")		// return the upper directory
				{
					if (!hierarchy.empty())
						hierarchy.pop();
				}
				else if (name == ".")	// remain in the current directory
				{
					;
				}
				else					// dive into the next directory
					hierarchy.push(name);
			}
			p = end;
			while (path[p] == '/')	// skip consecutive slashes
				++p;
		}
		// record the last directory if there is
		if (p != path.size())
		{
			string name = path.substr(p, end - p);
			if (!name.empty())
			{
				if (name == "..")
				{
					if (!hierarchy.empty())
						hierarchy.pop();
				}
				else if (name == ".")
				{
					;
				}
				else
					hierarchy.push(name);
			}
		}
		string ret;
		// Bottom-up arranging the directory name with one slash in between
		if (hierarchy.empty())
			ret += "/";
		else
		{
			while (!hierarchy.empty())
			{
				string name = hierarchy.top();
				hierarchy.pop();
				ret = "/" + name + ret;
			}
		}
		return ret;
	}
};
