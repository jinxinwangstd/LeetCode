class Solution {
public:
    int shortestWay(string source, string target) {
        int m = source.size(), n = target.size();
        int ans = 0, pos = m;
        int i = 0;
        while (i < n) {
            int next_pos = source.find(target[i], pos);
            if (next_pos == string::npos) {
                if (pos) {
                    pos = 0;
                    ans++;
                    continue;
                }
                else
                    return -1;
            }
            else {
                pos = next_pos + 1;
                i++;
            }
        }
        return ans;
    }
};

/*
 *
 */
