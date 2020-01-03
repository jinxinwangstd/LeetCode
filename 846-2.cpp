class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if (n % W != 0)
            return false;
        multiset<int> s(hand.begin(), hand.end());
        multiset<int>::iterator iter;
        while (!s.empty()) {
            int start = *s.begin();
            int end = start + W;
            for (int i = start; i < end; i++) {
                iter = s.find(i);
                if (iter == s.end())
                    return false;
                s.erase(iter);
            }
        }
        return true;
    }
};

/*
 * multiset
 */
