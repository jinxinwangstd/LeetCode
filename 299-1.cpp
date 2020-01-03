class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> occur1(10, 0);
        vector<int> occur2(10, 0);
        int n = secret.size();
        int num_bulls = 0, num_cows = 0;
        for (int i = 0; i < n; i++) {
            occur1[secret[i] - '0']++;
            occur2[guess[i] - '0']++;
            num_bulls += secret[i] == guess[i];
        }
        for (int i = 0; i < 10; i++)
            num_cows += min(occur1[i], occur2[i]);
        num_cows -= num_bulls;
        string res = to_string(num_bulls) + "A" + to_string(num_cows) + "B";
        return res;
    }
};

/*
 * array indexing.
 */
