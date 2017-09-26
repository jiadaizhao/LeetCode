class Excel {
public:
    Excel(int H, char W) {
        height = H;
        width = W - 'A' + 1;
        cells = vector<vector<Cell>>(height, vector<Cell>(width));
    }
    
    void set(int r, char c, int v) {
        int row = r - 1;
        int col = c - 'A';
        if (cells[row][col].val == v)
        {
            return;
        }
        int index = row * width + col;
        for (auto it = cells[row][col].count.begin(); it != cells[row][col].count.end(); ++it)
        {
            int nr = it->first / width;
            int nc = it->first % width;
            cells[nr][nc].neighbors.erase(index);
        }
                
        cells[row][col].count.clear();
        cells[row][col].val = v;
        vector<vector<bool>> visited = vector<vector<bool>>(height, vector<bool>(width));
        stack<pair<int, int>> St;
        topologicalSort(row, col, St, visited);
        
        while (!St.empty())
        {
            int nr = St.top().first;
            int nc = St.top().second;
            St.pop();
            if (cells[nr][nc].count.size())
            {
                cells[nr][nc].val = calculateSum(cells[nr][nc].count); 
            }                       
        }        
    }
    
    int get(int r, char c) {
        return cells[r - 1][c - 'A'].val;
    }
    
    int sum(int r, char c, vector<string> strs) {
        unordered_map<int, int> count;
        int row = r - 1;
        int col = c - 'A';
        int index = row * width + col;
        for (string& str : strs)
        {
            size_t loc = str.find(":");
            if (loc == string::npos)
            {
                int nr = stoi(str.substr(1)) - 1;
                int nc = str[0] - 'A';
                cells[nr][nc].neighbors.insert(index);
                ++count[nr * width + nc];
            }
            else
            {
                string leftTop = str.substr(0, loc);
                string rightBottom = str.substr(loc + 1);
                int rs = stoi(leftTop.substr(1)) - 1;
                int re = stoi(rightBottom.substr(1)) - 1;
                int cs = leftTop[0] - 'A';
                int ce = rightBottom[0] - 'A';
                for (int i = rs; i <= re; ++i)
                {
                    for (int j = cs; j <= ce; ++j)
                    {
                        cells[i][j].neighbors.insert(index);
                        ++count[i * width + j];
                    }
                }
            }
        }
        
        int s = calculateSum(count);        
        set(r, c, s);
        cells[r - 1][c - 'A'].count = count;
        return s;
    }
    
private:
    struct Cell {
        int val;
        unordered_map<int, int> count;
        unordered_set<int> neighbors;
        Cell ()
        {
            val = 0;
        }
    };
    vector<vector<Cell>> cells;
    int height;
    int width;
    
    void topologicalSort(int r, int c, stack<pair<int, int>>& St, vector<vector<bool>>& visited) {
        if (visited[r][c])
        {
            return;
        }
        
        visited[r][c] = true;
        for (auto it = cells[r][c].neighbors.begin(); it != cells[r][c].neighbors.end(); ++it)
        {
            int index = *it;
            topologicalSort(index / width, index % width, St, visited);
        }
        
        St.push({r, c});
    }
    
    int calculateSum(unordered_map<int, int>& count)
    {
        int sum = 0;
        for (auto it = count.begin(); it != count.end(); ++it)
        {
            int index = it->first;
            sum += cells[index / width][index % width].val * (it->second);
        }
        return sum;
    }
    
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */
 