class Solution {
public:
    int numPapers(vector<int>& citations, int h) {
        int res = 0;
        for (int c : citations)
            if (c >= h)
                res++;
        return res;
    }
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int max_cita = *max_element(citations.begin(), citations.end());
        int l = 0, r = max_cita, mid;
        while (r - l > 1) {
            mid = l + (r - l) / 2;
            if (numPapers(citations, mid) >= mid)
                l = mid;
            else
                r = mid;
        }
        if (numPapers(citations, r) >= r)
            return r;
        else
            return l;
    }
};
