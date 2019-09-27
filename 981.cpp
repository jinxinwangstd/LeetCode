// Do not use direct binary search, it would cause TLE
// With too many times of get, O(lgn) is not fast enough
class TimeMap {
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        if (!stores.count(key))
            stores[key] = vector<int>(1, -1);
        int last_id = stores[key].back();
        stores[key].insert(stores[key].end(), timestamp - stores[key].size(), last_id);
        if (!value_ids.count(value)) {
            value_ids[value] = values.size();
            values.push_back(value);
        }
        stores[key].push_back(value_ids[value]);
    }

    string get(string key, int timestamp) {
        int value_id = timestamp >= stores[key].size() ? stores[key].back() : stores[key][timestamp];
        if (value_id >= 0)
            return values[value_id];
        else
            return "";
    }
private:
    unordered_map<string, vector<int>> stores;
    vector<string> values;
    unordered_map<string, int> value_ids;
};
