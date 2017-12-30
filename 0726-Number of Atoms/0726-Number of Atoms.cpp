class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        int i = 0;
        map<string, int> table = helper(formula, i);
        string result;
        for (auto t : table) {
            result += t.first;
            if (t.second != 1) {
                result += to_string(t.second);
            }
        }
        return result;
    }
    
private:
    map<string, int> helper(string& s, int& i) {
        map<string, int> table;
        while (i < s.size() && s[i] != ')') {
            if (s[i] == '(') {
                ++i;
                map<string, int> next = helper(s, i);
                for (auto n : next) {
                    table[n.first] += n.second;
                }
            }
            else {
                int start = i++;
                while (i < s.size() && islower(s[i])) {
                    ++i;
                }
                
                string name = s.substr(start, i - start);
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                if (num == 0) {
                    num = 1;
                }
                table[name] += num;
            }
        }

        if (i < s.size()) {
            ++i;
            int num = 0;
            while (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                ++i;
            }

            if (num != 0) {
                for (auto& t : table) {
                    t.second *= num;
                }
            }
        }        
        
        return table;
    }
};
