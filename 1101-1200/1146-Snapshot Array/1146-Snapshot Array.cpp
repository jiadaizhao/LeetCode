class SnapshotArray {
public:
    SnapshotArray(int length) {
        sid = 0;
        arr = vector<vector<pair<int, int>>>(length);
    }
    
    void set(int index, int val) {
        while (arr[index].size() && arr[index].back().first == sid) {
            arr[index].pop_back();
        }
        arr[index].emplace_back(sid, val);
    }
    
    int snap() {
        return sid++;
    }
    
    int get(int index, int snap_id) {
        if (arr[index].size() == 0) {
            return 0;
        }
        auto it = lower_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id + 1, 0));
        return (it == arr[index].begin()) ? 0 : (--it)->second;
    }

private:
    int sid;
    vector<vector<pair<int, int>>> arr;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
