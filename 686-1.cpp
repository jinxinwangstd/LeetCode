class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        vector<int> anchors;
        int anchor = -1;
        while ((anchor = A.find(B[0], anchor + 1)) != string::npos)
            anchors.push_back(anchor);
        if (anchors.empty())
            return -1;
        int res = INT_MAX;
        for (int i = 0; i < anchors.size(); i++) {
            int repeating = 1;
            anchor = anchors[i];
            for (int j = 0; j < B.size(); j++) {
                if (anchor == A.size()) {
                    anchor = 0;
                    repeating++;
                }
                if (B[j] == A[anchor])
                    anchor++;
                else {
                    repeating = INT_MAX;
                    break;
                }
            }
            res = min(res, repeating);        
        }
        return res != INT_MAX ? res : -1;
    }
};

/*
 * Simulation
 */
