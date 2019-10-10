class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int ans = 0;
        int m = words.size();
        for (int i = 0; i < m; i++) {
            string word = words[i];
            int n = word.size();
            int j = 0, pos = -1;
            while (j < n) {
                if ((pos = S.find(word[j], pos + 1)) == string::npos)
                    break;
                j++;
            }
            if (j == n)
                ans++;
        }
        return ans;
    }
};
