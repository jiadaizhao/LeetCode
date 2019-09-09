class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr): a(arr) {
        for (int i = 0; i < arr.size(); ++i) {
            pos[arr[i]].push_back(i);
        }
        tree = vector<int>(arr.size() * 4, -1);
        build_tree(1, 0, arr.size() - 1);
    }
    
    int query(int left, int right, int threshold) {
        pair<int, int> ans = query(1, 0, a.size() - 1, left, right);
        if (ans.second >= threshold) {
            return ans.first;
        }
        return -1;
    }
    
private:
    unordered_map<int, vector<int>> pos;
    vector<int> tree;
    vector<int> a;
    
    void build_tree(int tree_pos, int l, int r) {
        if (l == r) {
            tree[tree_pos] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build_tree(tree_pos * 2, l, mid);
        build_tree(tree_pos * 2 + 1, mid + 1, r);
        if (tree[tree_pos * 2] != -1 && get_occurrence(tree[tree_pos * 2], l, r) * 2 > r - l + 1) {
            tree[tree_pos] = tree[tree_pos * 2];
        }
        else if (tree[tree_pos * 2 + 1] != -1 && get_occurrence(tree[tree_pos * 2 + 1], l, r) * 2 > r - l + 1) {
            tree[tree_pos] = tree[tree_pos * 2 + 1];
        }
    }
    
    pair<int, int> query(int tree_pos, int l, int r, int queryl, int queryr) {
        if (l > queryr || r < queryl) {
            return make_pair(-1, -1);
        }
        if (queryl <= l && r <= queryr) {
            if (tree[tree_pos] == -1) {
                return make_pair(-1, -1);
            }
            int occ = get_occurrence(tree[tree_pos], queryl, queryr);
            if (occ * 2 > queryr - queryl + 1) {
                return make_pair(tree[tree_pos], occ);
            }
            else {
                return make_pair(-1, -1);
            }
        }
        int mid = (l + r) >> 1;
        pair<int, int> res_l = query(tree_pos * 2, l, mid, queryl, queryr);
        if (res_l.first > -1) {
            return res_l;
        }
        pair<int, int> res_r = query(tree_pos * 2 + 1, mid + 1, r, queryl, queryr);
        if (res_r.first > -1) {
            return res_r;
        }
        return make_pair(-1, -1);
    }
    
    int get_occurrence(int num, int l, int r) {
        auto iter = pos.find(num);
        if (iter == pos.end()) {
            return 0;
        }
        const auto& vec = iter->second;
        auto iter_l = lower_bound(vec.begin(), vec.end(), l);
        if (iter_l == vec.end()) {
            return 0;
        }
        auto iter_r = upper_bound(vec.begin(), vec.end(), r);
        return iter_r - iter_l;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
