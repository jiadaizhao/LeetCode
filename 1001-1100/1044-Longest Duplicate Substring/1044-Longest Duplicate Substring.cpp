class Solution {
public:
    string longestDupSubstring(string S) {
        int low = 1, high = S.size();
        string maxLenS;
        while (low < high) {
            int mid = low + (high - low) / 2;
            string res = search(S, mid);
            if (res.size()) {
                maxLenS = res;
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return maxLenS;
    }

private:
    string search(string& S, int num) {
        int BASE = 33, MOD = (1 << 20) - 1, hashcode = 0, p = 1;
        for (int i = 0; i < num; ++i) {
            p = p * BASE % MOD;
        }

        unordered_map<int, vector<int>> table;
        for (int i = 0; i < S.size(); ++i) {
            hashcode = (hashcode * BASE + S[i]) % MOD;
            if (i < num - 1) {
                continue;
            }

            if (i >= num) {
                hashcode = hashcode - (S[i - num] * p) % MOD;
                if (hashcode < 0) {
                    hashcode += MOD;
                }

                for (int j : table[hashcode]) {
                    int k;
                    for (k = 0; k < num; ++k) {
                        if (S[i - k] != S[j - k]) {
                            break;
                        }
                    }

                    if (k == num) {
                        return S.substr(i - num + 1, num);
                    }
                }
            }

            table[hashcode].push_back(i);
        }

        return "";
    }
};
