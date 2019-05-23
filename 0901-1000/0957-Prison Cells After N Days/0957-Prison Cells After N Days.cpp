class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> table;
        unordered_map<int, int> visited;
        int index = N - 1;
        for (int i = 0; i < N; ++i) {
            cells = findNext(cells);
            int num = convert(cells);
            if (visited.count(num)) {
                index = visited[num] + (N - 1 - visited[num]) % (i - visited[num]);
                break;
            }
            table.push_back(num);
            visited[num] = i;
        }
        return numToArray(table[index]);
    }
    
private:
    vector<int> findNext(vector<int>& curr) {
        vector<int> next(8);
        for (int i = 1; i < 7; ++i) {
            next[i] = !(curr[i - 1] ^ curr[i + 1]);
        }
        return next;
    }
    
    int convert(vector<int>& cells) {
        int num = 0;
        for (int i = 0; i < cells.size(); ++i) {
            num = num * 2 + cells[i];
        }
        return num;
    }
    
    vector<int> numToArray(int num) {
        vector<int> result(8);
        for (int i = 7; i >= 0 && num; --i) {
            result[i] = num & 1;
            num >>= 1;
        }
        return result;
    }
};
