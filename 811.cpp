class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> counts;
        int n = cpdomains.size();
        for (int i = 0; i < n; i++) {
            int start = 0, end = 0;
            end = cpdomains[i].find(' ', start);
            int count = stoi(cpdomains[i].substr(start, end - start));
            start = end + 1;
            counts[cpdomains[i].substr(start)] += count;
            while ((end = cpdomains[i].find('.', start)) != string::npos) {
                start = end + 1;
                counts[cpdomains[i].substr(start)] += count;
            }
        }
        vector<string> res;
        for (unordered_map<string, int>::iterator iter = counts.begin(); iter != counts.end(); iter++) {
            string cp = to_string(iter->second) + " " + iter->first;
            res.push_back(cp);
        }
        return res;
    }
};
