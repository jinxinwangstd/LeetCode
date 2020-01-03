class MyHashMap {
public:
    /* Initialize your data structure here. */
    MyHashMap() {
        const int n = 1e6 + 5;
        table.assign(n, -1);
    }

    /* value will always be non-negative. */
    void put(int key, int value) {
        table[key] = value;
    }

    /* Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key. */
    int get(int key) {
        return table[key];
    }

    /* Removes the mapping of the specified value key if this map contains a mapping for the key. */
    void remove(int key) {
        table[key] = -1;
    }
private:
    vector<int> table;
};

/*
 * Hash map
 */
