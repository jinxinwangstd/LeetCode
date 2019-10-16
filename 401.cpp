class Solution {
public:
    void dfs(vector<int>& res, int time, int pos, int n, bool isHour) {
        if (n == 0) {
            if (isHour && time < 12)
                res.push_back(time);
            if (!isHour && time < 60)
                res.push_back(time);
            return;
        }
        int max_val = isHour ? 4 : 6;
        for (int i = pos; i <= max_val; i++) {
            time |= (1 << i);
            dfs(res, time, i + 1, n - 1, isHour);
            time &= ~(1 << i);
        }
        return;
    }
    void generateTimes(vector<int>& res, int n, bool isHour) {
        dfs(res, 0, 0, n, isHour);
        return;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        vector<int> hours, minutes;
        for (int i = 0; i <= min(num, 4); i++) {
            int hour_lights = i, minute_lights = num - i;
            hours.clear();
            minutes.clear();
            generateTimes(hours, hour_lights, true);
            generateTimes(minutes, minute_lights, false);
            int m = hours.size(), n = minutes.size();
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    string time;
                    time += to_string(hours[j]);
                    time += ":";
                    if (minutes[k] < 10)
                        time += "0";
                    time += to_string(minutes[k]);
                    res.push_back(time);
                }
            }
        }
        return res;
    }
};
