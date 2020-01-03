class Solution {
public:
    vector<int> last_cost, cur_cost;
    int minCost(vector< vector<int> >& costs) {
        int num_house = costs.size();
        if (!num_house)
            return 0;
        last_cost.resize(3);
        cur_cost.resize(3);
        int index = 1;
        cur_cost = costs[0];
        while (index < num_house) {
            last_cost = cur_cost;
            cur_cost[0] = costs[index][0] + min(last_cost[1], last_cost[2]);
            cur_cost[1] = costs[index][1] + min(last_cost[0], last_cost[2]);
            cur_cost[2] = costs[index][2] + min(last_cost[0], last_cost[1]);
            index++;
        }
        return min(min(cur_cost[0], cur_cost[1]), cur_cost[2]);
    }
};
