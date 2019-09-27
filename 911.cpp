class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        const int N = 5050;
        int n = persons.size();
        leaders = vector<int>(n, -1);
        ts = vector<int>(n, -1);
        int most_votes = 0;
        vector<int> counts(N, 0);
        for (int i = 0; i < n; i++) {
            ts[i] = times[i];
            counts[persons[i]]++;
            if (counts[persons[i]] >= most_votes) {
                most_votes = counts[persons[i]];
                leaders[i] = persons[i];
            }
            else
                leaders[i] = leaders[i - 1];
        }
        return;
    }

    int q(int t) {
        vector<int>::iterator iter = upper_bound(ts.begin(), ts.end(), t);
        int index = distance(ts.begin(), iter);
        return leaders[index - 1];
    }
private:
    vector<int> leaders, ts;
};
