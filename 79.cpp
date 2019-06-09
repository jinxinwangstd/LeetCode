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
	// This function finds whether word[p, end) exists starting at position (r, c)
	bool findNextChar(vector< vector<char> >& board, string& word, int p, int r, int c)
	{
		// base cases
		if (p == (int) word.size())
			return true;
		if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
			return false;
		if (board[r][c] != word[p])
			return false;
		bool ret = false;
		char cur = board[r][c];
		board[r][c] = '*';		// use special character to indicate we have visited it and avoid revisits
		// Using recursive relation to find rest word characters
		ret = findNextChar(board, word, p + 1, r + 1, c) ||
		      findNextChar(board, word, p + 1, r - 1, c) ||
		      findNextChar(board, word, p + 1, r, c + 1) ||
		      findNextChar(board, word, p + 1, r, c - 1);
		board[r][c] = cur;		// recover board
		return ret;
	}
	// This function determines whether a word exists in a board in consecutive positions based on floodfill algorithm
	bool exist(vector< vector<char> >& board, string word)
	{
		if (word.empty())						// corner case: the word is empty then the result is true
			return true;
		if (board.empty() || board[0].empty())	// corner case: the board is empty then the result is false
			return false;
		int m = (int) board.size(), n = (int) board[0].size();
		// Find valid word starting positions
		for (int i = 0; i != m; ++i)
			for (int j = 0; j != n; ++j)
				if (board[i][j] == word[0])
					if (findNextChar(board, word, 0, i, j))
						return true;
		return false;
	}
};
