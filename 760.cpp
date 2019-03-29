#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

// Reverse indexing
vector<int> anagramMappings(vector<int>& A, vector<int>& B)
{
	vector<int> ret;
	map<int, int> B_pos;
	int A_size = A.size(), B_size = B.size();
	for (int i = 0; i != B_size; ++i)
		B_pos[B[i]] = i;
	for (int i = 0; i != A_size; ++i)
		ret.push_back(B_pos[A[i]]);
	return ret;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	return 0;
}
