#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	const int num = 9;
	const int num_sub = 3;
	bool isValidSudoku(vector<vector<char>>& board)
	{
		bitset<10> record;		// Use a bitset to record whether an integer repeats
		// Check the validality of each row
		for (int i = 0; i != num; ++i)
		{
			record.reset();
			for (int j = 0; j != num; ++j)
			{
				if (board[i][j] != '.')
				{
					int elem = board[i][j] - '0';
					if (record.test(elem))
						return false;
					else
						record.set(elem);
				}
			}
		}
		// Check the validality of each column
		for (int j = 0; j != num; ++j)
		{
			record.reset();
			for (int i = 0; i != num; ++i)
			{
				if (board[i][j] != '.')
				{
					int elem = board[i][j] - '0';
					if (record.test(elem))
						return false;
					else
						record.set(elem);
				}
			}
		}
		// Check the validality of each sub grid
		for (int i = 0; i != num_sub; ++i)
		{
			for (int j = 0; j != num_sub; ++j)
			{
				record.reset();
				for (int m = 0; m != num_sub; ++m)
				{
					for (int n = 0; n != num_sub; ++n)
					{
						if (board[i * num_sub + m][j * num_sub + n] != '.')
						{
							int elem = board[i * num_sub + m][j * num_sub + n] - '0';
							if (record.test(elem))
								return false;
							else
								record.set(elem);
						}
					}
				}
			}
		}
		return true;
	}
};
