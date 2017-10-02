class Solution {
public:
    string nextClosestTime(string time) {
        vector<bool> used(10);
        used[time[0] - '0'] = true;
        used[time[1] - '0'] = true;
        used[time[3] - '0'] = true;
        used[time[4] - '0'] = true;
        int curr = 60 * stoi(time.substr(0 , 2)) + stoi(time.substr(3, 2));
        while (true) {
            curr = (curr + 1) % 1440;
            int h1 = curr / 60 / 10;
            if (!used[h1]) {
                continue;
            }
            int h2 = curr / 60 % 10;
            if (!used[h2]) {
                continue;
            }
            int m1 = curr % 60 / 10;
            if (!used[m1]) {
                continue;
            }
            int m2 = curr % 60 % 10;
            if (!used[m2]) {
                continue;
            }
            break;
        }
        
        int hour = curr / 60;
        int min = curr % 60;
        
        return (hour <= 9 ? "0" : "") + to_string(hour) + ":" + (min <= 9 ? "0" : "") + to_string(min);
    }
};

class Solution {
public:
    string nextClosestTime(string time) {
        int start = 60 * stoi(time.substr(0 , 2)) + stoi(time.substr(3, 2));
        int minDiff = 1440;
        int result = start;
        unordered_set<int> allowed;
        for (char t : time) {
            if (t != ':') {
                allowed.insert(t - '0');
            }            
        }
        
        for (int h1 : allowed) {
            for (int h2 : allowed) {
                int h = h1 * 10 + h2;
                if (h < 24) {
                    for (int m1 : allowed) {
                        for (int m2 : allowed) {
                            int m = m1 * 10 + m2;
                            if (m < 60) {
                                int candidate = h * 60 + m;
                                int diff = (candidate + 1440 - start) % 1440;
                                if (diff > 0 && diff < minDiff) {
                                    result = candidate;
                                    minDiff = diff;
                                }
                            }
                        }
                    }                    
                }
            }            
        }
        
        int hour = result / 60;
        int min = result % 60;
        
        return (hour <= 9 ? "0" : "") + to_string(hour) + ":" + (min <= 9 ? "0" : "") + to_string(min);
    }
};
