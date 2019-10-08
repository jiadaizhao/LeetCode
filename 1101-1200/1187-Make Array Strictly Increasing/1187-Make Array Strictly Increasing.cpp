class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        unordered_map<int, int> states;
        states[-1] = 0;
        for (int a : arr1) {
            unordered_map<int, int> temp;
            for (auto p : states) {
                int key = p.first;
                if (a > key) {
                    if (!temp.count(a) || states[key] < temp[a]) {
                        temp[a] = states[key];
                    }
                }
                
                auto it = upper_bound(arr2.begin(), arr2.end(), key);
                if (it != arr2.end()) {
                    if (!temp.count(*it) || states[key] + 1 < temp[*it]) {
                        temp[*it] = states[key] + 1;
                    }
                }
            }            
            
            swap(states, temp);
        }
        
        if (states.size()) {
            int minNum = INT_MAX;
            for (auto p : states) {
                minNum = min(minNum, p.second);
            }
            return minNum;
        }
        else {
            return -1;
        }
    }
};
