#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class UnionFind
{
private:
	vi p, rank;
public:
	UnionFind(int N)
	{
		p.assign(N, 0);
		rank.assign(N, 0);
		for (int i = 0; i < N; ++i)
			p[i] = i;
	}
	int findSet(int u)
	{
		return p[u] == u ? u : p[u] = findSet(p[u]);
	}
	int isSameSet(int u, int v)
	{
		return findSet(u) == findSet(v);
	}
	void unionSet(int u, int v)
	{
		if (!isSameSet(u, v))
		{
			int x = findSet(u), y = findSet(v);
			if (rank[x] > rank[y])
				p[y] = x;
			else
			{
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};

class Solution
{
public:
	int m, n;
	int Id(int i, int j)
	{
		return i * n + j;
	}
	void solve(vector<vector<char>>& board)
	{
		if (board.empty() || board[0].empty())
			return;
		m = board.size();
		n = board[0].size();
		UnionFind UF(m * n + 1);
		int dummy_id = m * n;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O')
					UF.unionSet(Id(i, j), dummy_id);
				else if (board[i][j] == 'O')
				{
					if (board[i + 1][j] == 'O')
						UF.unionSet(Id(i, j), Id(i + 1, j));
					if (board[i - 1][j] == 'O')
						UF.unionSet(Id(i, j), Id(i - 1, j));
					if (board[i][j - 1] == 'O')
						UF.unionSet(Id(i, j), Id(i, j - 1));
					if (board[i][j + 1] == 'O')
						UF.unionSet(Id(i, j), Id(i, j + 1));
				}
			}
		}
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (!UF.isSameSet(Id(i, j), dummy_id))
					board[i][j] = 'X';

	}
};
