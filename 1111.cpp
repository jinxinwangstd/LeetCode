class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> res(n, -1);
        int depthA = 0, depthB = 0;
        int max_depthA = 0, max_depthB = 0;
        /*
         * As long as the parentheses string is valid,
         * a left parentheses would increment the depth by one,
         * and a right parenthese would decrement the depth by
         * one. To minimize the maximum depth of two subsequence,
         * we need to distribute the parentheses evenly.
         */
        for (int i = 0; i < n; i++) {
            // Distribute the left parentheses to the lower depth subsequence
            if (seq[i] == '(') {
                if (depthA > depthB) {
                    res[i] = 1;
                    depthB++;
                }
                else {
                    res[i] = 0;
                    depthA++;
                }
            }
            // distribute the right parentheses to the higher depth subsequence
            else {
                if (depthA > depthB) {
                    res[i] = 0;
                    depthA--;
                }
                else {
                    res[i] = 1;
                    depthB--;
                }
            }
        }
        return res;
    }
};
