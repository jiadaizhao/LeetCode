class Solution {
public:
    int countTriplets(vector<int>& A) {
        int total = 0;
        unordered_map<int, int> table;
        for (int a : A) {
            for (int b : A) {
                ++table[a & b];
            }
        }

        for (int a : A) {
            for (auto p : table) {
                if (a & p.first == 0) {
                    total += p.second;
                }
            }
        }
        return total;
    }
};

class Solution {
public:
    int countTriplets(vector<int>& A) {
        int total = 0;
        int table[1 << 16] = {0};
        for (int a : A) {
            for (int b : A) {
                ++table[a & b];
            }
        }

        for (int a : A) {
            for (int i = 0; i < (1 << 16); ++i) {
                if ((a & i) == 0) {
                    total += table[i];
                }
                else {
                    i += (a & i) - 1;
                }
            }
        }
        return total;
    }
};
