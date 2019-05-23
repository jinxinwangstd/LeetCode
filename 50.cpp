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
	map<ll, double> memo;	// for sparse memoization table we can use the map container
	// Calculate the exponention of a number based on divide and conquer algorithm
	double myPowHelper(double x, ll n)
	{
		if (!n)			// base case
			return 1;
		if (memo.count(n))		// we have already calculated it
			return memo[n];
		// as we use divide and conquer, the n values we would go through are sparse but may be large
		if (n % 2)
			return memo[n] = x * myPowHelper(x, n - 1);
		else
			return memo[n] = myPowHelper(x, n / 2) * myPowHelper(x, n / 2);
	}
	double myPow(double x, int n)
	{
		bool neg = n < 0;
		double ret = myPowHelper(x, abs((ll) n));
		return neg ? 1 / ret : ret;
	}
};
