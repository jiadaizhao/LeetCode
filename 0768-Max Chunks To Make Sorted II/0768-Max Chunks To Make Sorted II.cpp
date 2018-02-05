class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        vector<int> A(arr.begin(), arr.end());
        sort(A.begin(), A.end());
        for (int i = 0; i < n; ++i) {
            ++count;
            if (arr[i] == A[i]) {
                continue;
            }
            
            int num = 0;
            unordered_map<int, int> table;
            while (i < n) {
                if (--table[A[i]] < 0) {
                    ++num;
                }
                else {
                    --num;
                }
                if (++table[arr[i]] > 0) {
                    ++num;
                }
                else {
                    --num;
                }
                if (num == 0) {
                    break;
                }
                ++i;
            }
        }
        return count;
    }
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> index(n);
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&arr](int i1, int i2){return arr[i1] == arr[i2] ? i1 < i2 : arr[i1] < arr[i2];});
        
        int maxNum = 0, count = 0;
        for (int i = 0; i < index.size(); ++i) {
            maxNum = max(maxNum, index[i]);
            if (maxNum == i) ++count;
        }
        
        return count;
    }
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> maxLeft(n), minRight(n);
        maxLeft[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], arr[i]);
        }
        
        minRight[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            minRight[i] = min(minRight[i + 1], arr[i]);
        }
        
        int count = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (maxLeft[i] <= minRight[i + 1]) ++count;
        }
        
        return count;
    }
};
