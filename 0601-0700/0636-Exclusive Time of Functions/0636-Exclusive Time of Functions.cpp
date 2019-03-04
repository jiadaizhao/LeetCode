class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> St;
        vector<int> time(n);
        int prev = 0;        
        for (string str : logs) {
            stringstream ss(str);
            string s;
            getline(ss, s, ':');
            int id = stoi(s);
            getline(ss, s, ':');
            bool start = (s == "start");
            getline(ss, s, ':');
            int timestamp = stoi(s);
            if (start) {
                if (!St.empty()) {
                    time[St.top()] += timestamp - prev;                    
                }
                prev = timestamp;
                St.push(id);
            }
            else {
                time[id] += timestamp - prev + 1;
                St.pop();
                prev = timestamp + 1;
            }
        }
        
        return time;
    }
};
