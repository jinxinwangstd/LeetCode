#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

// Mapping character to integer
bool judgeCircle(string moves)
{
	int vertical = 0, horizontal = 0;
	for (string::iterator iter = moves.begin(); iter != moves.end(); ++iter)
	{
		if (*iter == 'U')
			++vertical;
		else if (*iter == 'D')
			--vertical;
		else if (*iter == 'R')
			++horizontal;
		else if (*iter == 'L')
			--horizontal;
	}
	return (!vertical && !horizontal);
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	return 0;
}
