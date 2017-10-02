class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int N = flowers.size();
        set<int> table;
        for (int i = 0; i < N; ++i) {
            auto it = table.insert(flowers[i]).first;
            auto it1 = it;
            --it1;
            if (it1 != table.end() && *it - *it1 == k + 1) {
                return i + 1;
            }
            auto it2 = it;
            ++it2;
            if (it2 != table.end() && *it2 - *it == k + 1) {
                return i + 1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int N = flowers.size();
        vector<int> days(N);
        for (int i = 0; i < N; ++i) {
            days[flowers[i] - 1] = i + 1;
        }
        
        int left = 0, right = k + 1;
        int result = INT_MAX;
        for (int i = 0; i < N; ++i) {
            if (days[i] < days[left] || days[i] <= days[right]) {
                if (i == right) {
                    result = min(result, max(days[left], days[right]));
                }
                left = i;
                right = i + k + 1;
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};
