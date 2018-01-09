class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        stringstream ss(ip);
        string s;
        long long num = 0;
        while (getline(ss, s, '.')) {
            num = num * 256 + stoi(s);
        }

        vector<string> result;

        while (n > 0) {
            int least = num & (-num);
            int count = min(least, upperLimit(n));
            convert(num, count, result);
            num += count;
            n -= count;
        }
        return result;
    }

private:
    int upperLimit(int n) {
        int count = 0;;
        while (n) {
            ++count;
            n >>= 1;
        }
        return 1 << (count - 1);
    }
    void convert(long long start, int count, vector<string>& result) {
        long long curr = start;
        vector<int> path;
        while (curr) {
            path.push_back(curr % 256);
            curr /= 256;
        }

        while (path.size() < 4) {
            path.push_back(0);
        }

        string s;
        for (int i = 3; i >= 0; --i) {
            if (s.size()) {
                s += '.';
            }
            s += to_string(path[i]);
        }
        s += '/';
        int num = 0;
        while (count) {
            ++num;
            count >>= 1;
        }
        s += to_string(33 - num);
        result.push_back(s);
    }
};
