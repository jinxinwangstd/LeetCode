class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> rounds;
        for (auto record : ops) {
            if (record[0] == '+') {
                int round2 = rounds.top();
                rounds.pop();
                int round1 = rounds.top();
                rounds.pop();
                rounds.push(round1);
                rounds.push(round2);
                rounds.push(round1 + round2);
            }
            else if (record[0] == 'D') {
                rounds.push(2 * rounds.top());
            }
            else if (record[0] == 'C') {
                rounds.pop();
            }
            else
                rounds.push(stoi(record));
        }
        int sum = 0;
        while (!rounds.empty()) {
            sum += rounds.top();
            rounds.pop();
        }
        return sum;
    }
};
