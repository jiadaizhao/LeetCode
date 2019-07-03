class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = 1;
        vector<int> center2 = {2};
        while ((1 << level) <= label) {
            center2.push_back(center2.back() * 2 + 1);
            ++level;
        }

        vector<int> result(level);
        result.back() = label;
        bool reverse = true;
        int next = label / 2;
        for (int i = level - 2; i >= 0; --i) {
            result[i] = reverse ? center2[i] - next : next;
            next >>= 1;
            reverse = !reverse;
        }

        return result;
    }
};
