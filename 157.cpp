#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution
{
public:
	/**
	 * @param buf Destination buffer
	 * @param n   Number of characters to read
	 * @return    The number of actual characters read
	 */
	int read(char *buf, int n)
	{
		int len = 0;
		while (len < n)
		{
			int read_len = read4(buf);
			if (read_len)
			{
				len += read_len;
				buf += read_len;
			}
			else
				return len;
		}
		while (len > n)
		{
			buf--;
			*buf = '\0';
			len--;
		}
		return len;
	}
};
