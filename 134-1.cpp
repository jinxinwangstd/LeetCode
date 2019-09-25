class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int num_stations = gas.size();
        for (int i = 0; i < num_stations; ++i) {
            if (gas[i] >= cost[i]) {
                int count = 1;
                int s_i = i;
                int g = gas[s_i], c = cost[s_i];
                bool able_complete = true;
                while (able_complete && count < num_stations) {
                    s_i = s_i + 1 == num_stations ? 0 : s_i + 1;
                    g += gas[s_i];
                    c += cost[s_i];
                    if (g < c)
                        able_complete = false;
                    count++;
                }
                if (able_complete)
                    return i;
            }
        }
        return -1;
    }
};
