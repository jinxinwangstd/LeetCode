#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class Bucket
{
public:
	bool used = false;
	int min_val = INT_MAX;
	int max_val = INT_MIN;
};

class Solution
{
public:
	int maximumGap(vector<int>& nums)
	{
		if (nums.size() < 2)
			return 0;
		int n = nums.size();
		int mini = *(min_element(nums.begin(), nums.end()));
		int maxi = *(max_element(nums.begin(), nums.end()));
		int bucket_size = max(1, (maxi - mini) / (n - 1));
		int bucket_num = (maxi - mini) / bucket_size + 1;

		vector<Bucket> buckets(bucket_num);
		for (int num : nums)
		{
			int bucket_index = (num - mini) / bucket_size;
			buckets[bucket_index].used = true;
			buckets[bucket_index].min_val = min(buckets[bucket_index].min_val, num);
			buckets[bucket_index].max_val = max(buckets[bucket_index].max_val, num);
		}
		int ret = 0, prev_bucket_max = mini;
		for (int i = 0; i < bucket_num; ++i)
		{
			if (!buckets[i].used)
				continue;
			ret = max(ret, buckets[i].min_val - prev_bucket_max);
			prev_bucket_max = buckets[i].max_val;
		}
		return ret;
	}
};
