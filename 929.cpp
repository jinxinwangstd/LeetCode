class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> record;
        int n = emails.size();
        for (int i = 0; i < n; i++) {
            string email = emails[i];
            string::iterator iter = email.begin();
            while (iter != email.end()) {
                if (*iter == '.')
                    iter = email.erase(iter);
                else if (*iter == '+') {
                    int pos = email.find('@', distance(email.begin(), iter)); // pos is the distance from start
                    iter = email.erase(iter, next(email.begin(), pos));
                }
                else if (*iter == '@')
                    break;
                else
                    iter++;
            }
            record.insert(email);
        }
        return record.size();                                                             
    }
};

