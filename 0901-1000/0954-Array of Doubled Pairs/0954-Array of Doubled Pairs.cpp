class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        vector<int> A1, A2;
        for (int a : A) {
            if (a >= 0) {
                A1.push_back(a);
            }
            else {
                A2.push_back(abs(a));
            }
        }
        return canReorder(A1) && canReorder(A2);
    }
    
private:
    bool canReorder(vector<int>& A) {
        map<int, int> table;
        for (int a : A) {
            ++table[a];
        }
        
        for (auto p : table) {
            if (p.first == 0) {
                if (p.second & 1) {
                    return false;
                } 
            }
            else if (p.second > 0) {
                if (table[p.first * 2] < p.second) {
                    return false;
                }
                table[p.first * 2] -= p.second;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> table;
        for (int a : A) {
            ++table[a];
        }
        vector<int> keys;
        for (auto p : table) {
            keys.push_back(p.first);
        }
        sort(keys.begin(), keys.end(), [](int x, int y){return abs(x) < abs(y);});
        for (int key : keys) {
            if (table[key] > table[key * 2]) {
                return false;
            }
            table[key * 2] -= table[key];
        }
        return true;
    }
};
