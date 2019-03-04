class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead;
        for (string s : deadends) {
            dead.insert(s);
        }
        
        int count = -1;
        queue<string> Q;
        if (dead.find("0000") != dead.end()) {
            return -1;
        }
        unordered_set<string> visited;
        Q.push("0000");
        visited.insert("0000");
        while (!Q.empty()) {            
            int qs = Q.size();
            ++count;
            for (int i = 0; i < qs; ++i) {
                string s = Q.front();
                Q.pop();
                if (s == target) {
                    return count;
                }
                                
                for (int j = 0; j < 4; ++j) {
                    for (int k = 0; k < 2; ++k) {
                        string temp(s);
                        if (k == 0) {
                            if (temp[j] == '9') {
                                temp[j] = '0';
                            }
                            else {
                                ++temp[j];
                            }
                        }
                        else {
                            if (temp[j] == '0') {
                                temp[j] = '9';
                            }
                            else {
                                --temp[j];
                            }
                        }
                        if (dead.find(temp) == dead.end() && visited.find(temp) == visited.end()) {
                            Q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }                
            }
        }
        
        return -1;
    }
};
