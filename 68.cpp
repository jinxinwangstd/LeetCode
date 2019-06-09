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
	// This function re-arranges an article so that the words in every line is aligned evenly
	vector<string> fullJustify(vector<string>& words, int maxWidth)
	{
		vector<string> ret;
		int i = 0;
		// Linear scan every word and put them into the corresponding lines
		while (i < (int) words.size())
		{
			string cur_line;
			int num_words = 0, estimated_width = 0;
			vector<string> cur_words;	// record words assigned to current line
			// put words into current line until our estimated width exceeds the limit
			while (i < (int) words.size() && estimated_width < maxWidth)
			{
				// update the context
				estimated_width += num_words ? (1 + words[i].size()) : words[i].size();
				++num_words;
				cur_words.push_back(words[i]);
				++i;
			}
			// if estimated width is over the limit, then the last word needs to be dropped
			if (estimated_width > maxWidth)
			{
				// recover the context
				--num_words;
				cur_words.pop_back();
				--i;
				estimated_width -= num_words ? (1 + words[i].size()) : words[i].size();
			}
			// arrange the positions of every word in our current line
			if (i == (int) words.size())		// last line
			{
				// arrange every word with one space in between
				for (int i = 0; i != num_words; ++i)
				{
					if (!i)		// first word
						cur_line += cur_words[i];
					else		// other words
						cur_line += (" " + cur_words[i]);
				}
				cur_line += string(maxWidth - cur_line.size(), ' ');	// add remaining spaces
			}
			else								// not last line
			{
				int num_space = (maxWidth - estimated_width) + (num_words - 1);
				if (num_words > 1)	// more than one word in the line
				{
					// calculate the number of spaces between words
					int even_num_space = num_space / (num_words - 1);
					int extra_num_space = num_space % (num_words - 1);
					for (int i = 0; i != num_words; ++i)
					{
						if (!i)		// first word
							cur_line += cur_words[i];
						else		// other words
						{
							if (extra_num_space)
							{
								cur_line += " ";
								extra_num_space--;
							}
							cur_line += (string(even_num_space, ' ') + cur_words[i]);
						}
					}
				}
				else				// only one word in the line
					cur_line += (cur_words[0] + string(num_space, ' '));
			}
			ret.push_back(cur_line);
		}
		return ret;
	}
};
