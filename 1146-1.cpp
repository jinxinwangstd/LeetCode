class SnapshotArray {
public:
    SnapshotArray(int length) {}
    
    void set(int index, int val) {
        changes[index] = val;
    }
    
    int snap() {
        snaps.push_back(changes);
        return snaps.size() - 1;
    }
    
    int get(int index, int snap_id) {
        if (!snaps[snap_id].count(index))
            return 0;
        return snaps[snap_id][index];
    }
private:
    vector<map<int, int>> snaps;
    map<int, int> changes;
};

