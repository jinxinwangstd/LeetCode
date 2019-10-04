class Solution {
public:
    string nextClosestTime(string time) {
        vector<char> chars;
        string origin = time;
        int n = time.size();
        for (int i = 0; i < n; i++)
            if (time[i] != ':')
                chars.push_back(time[i]);
        sort(chars.begin(), chars.end());
        bool find_next = false;
        for (int i = n - 1; i >= 0; i--) {
            char digit = time[i];
            if (digit == ':')
                continue;
            vector<char>::iterator iter = upper_bound(chars.begin(), chars.end(), digit);
            if (iter == chars.end())
                continue;
            // Lower bit of minutes
            if (i == n - 1)
                find_next = true;
            // Higher bit of minutes
            else if (i - 1 >= 0 && time[i - 1] == ':') {
                if (*iter < '6')
                    find_next = true;
            }
            // Lower bit of minutes
            else if (i + 1 < n && time[i + 1] == ':') {
                if (i == 0 || time[0] < '2')
                    find_next = true;
                else 
                    if (*iter < '4')
                        find_next = true;
            }
            // Higher bit of minutes
            else {
                if (*iter < '3')
                    find_next = true;
            }
            if (find_next) {
                time[i] = *iter;
                for (int j = i + 1; j < n; j++)
                    if (time[j] != ':')
                        time[j] = chars[0];
                break;
            }
        }
        if (!find_next) {
            for (int i = 0; i < n; i++)
                if (time[i] != ':')
                    time[i] = chars[0];
        }
        return time;
    }
};
