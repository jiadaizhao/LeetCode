class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {        
        unordered_map<int, int> table;
        for (int code : barcodes) {
            ++table[code];
        }
        priority_queue<pair<int, int>> pq;
        for (auto p : table) {
            pq.emplace(p.second, p.first);
        }
        
        int preKey = -1, preVal = -1;
        vector<int> result(barcodes.size());
        for (int i = 0; i < result.size(); ++i) {
            int val = pq.top().first;
            int key = pq.top().second;
            pq.pop();
            result[i] = key;
            if (preKey != -1 && preVal > 0) {
                pq.emplace(preVal, preKey);
            }
            preKey = key;
            preVal = --val;
        }
        
        return result;
    }
};


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {        
        int count[10001] = {0};
        int maxCode = 0;
        for (int code : barcodes) {
            if (++count[code] > count[maxCode]) {
                maxCode = code;
            }
        }
        
        int pos = 0;
        vector<int> result(barcodes.size());
        while (count[maxCode]-- > 0) {
            result[pos] = maxCode;
            pos += 2;
        }
        
        if (pos >= result.size()) {
            pos = 1;
        }
        
        for (int i = 1; i <= 10000; ++i) {
            while (count[i]-- > 0) {
                result[pos] = i;
                pos = pos + 2 < barcodes.size() ? pos + 2 : 1;
            }
        }
        
        return result;
    }
};
