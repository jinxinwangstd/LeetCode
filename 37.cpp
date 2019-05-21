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
	const int num_sub = 3;
	const int num = 9;
	// This function determines whether a board is valid sudoku board
	bool isValidSudoku(vector< vector<char> >& board)
	{
		bitset<10> row_checker;
		bitset<10> col_checker;
		bitset<10> square_checker;
		// Check the validality of each row
		for (int i = 0; i != num; ++i)
		{
			row_checker.reset();
			for (int j = 0; j != num; ++j)
			{
				if (board[i][j] != '.')
				{
					int elem = board[i][j] - '0';
					if (row_checker.test(elem))
						return false;
					else
						row_checker.set(elem);
				}
			}
		}
		// Check the validality of each column
		for (int j = 0; j != num; ++j)
		{
			col_checker.reset();
			for (int i = 0; i != num; ++i)
			{
				if (board[i][j] != '.')
				{
					int elem = board[i][j] - '0';
					if (col_checker.test(elem))
						return false;
					else
						col_checker.set(elem);
				}
			}
		}
		// Check the validality of each sub grid
		for (int i = 0; i != num_sub; ++i)
		{
			for (int j = 0; j != num_sub; ++j)
			{
				square_checker.reset();
				for (int m = 0; m != num_sub; ++m)
				{
					for (int n = 0; n != num_sub; ++n)
					{
						if (board[i * num_sub + m][j * num_sub + n] != '.')
						{
							int elem = board[i * num_sub + m][j * num_sub + n] - '0';
							if (square_checker.test(elem))
								return false;
							else
								square_checker.set(elem);
						}
					}
				}
			}
		}
		return true;
	}
	// Recursively extract a unsettled position and try all possible digits
	// If all the remaining position are settled, return true; otherwise, return false
	bool backtrack(vector< vector<char> >& board, vii& remains)
	{
		if (!isValidSudoku(board))	// the base board is not valid, then we cannot make next move and just return false
			return false;
		if (remains.empty())		// we have settled all remaining positions, return true
			return true;
		// for the next remaining position, try all possible digits
		ii next_pos = remains[remains.size() - 1];
		remains.pop_back();
		for (int i = 0; i != num; ++i)
		{
			board[next_pos.first][next_pos.second] = '1' + i;
			bool ret = backtrack(board, remains);		// arrange the next remaining position
			if (ret)
				return ret;
		}
		// all possible digits are not valid, we should recover the board
		board[next_pos.first][next_pos.second] = '.';	// cause we have tried to settle next few positions, we need to reset them to '.'
		remains.push_back(next_pos);
		return false;
	}
	void solveSudoku(vector< vector<char> >& board)
	{
		vii remains;
		// Record all remaining positions in the initial board
		for (int i = 0; i != num; ++i)
			for (int j = 0; j != num; ++j)
				if (board[i][j] == '.')
					remains.push_back(make_pair(i, j));
		// Use backtracking to solve the initial board
		backtrack(board, remains);
		return;
	}
};
