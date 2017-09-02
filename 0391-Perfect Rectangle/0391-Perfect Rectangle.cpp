class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        if (n == 0)
        {
            return false;
        }
        
        int area = 0;
        int x1 = INT_MAX, y1 = INT_MAX;
        int x2 = INT_MIN, y2 = INT_MIN;
        unordered_set<string> table;
        for (auto& rec : rectangles)
        {
            x1 = min(x1, rec[0]);
            y1 = min(y1, rec[1]);
            x2 = max(x2, rec[2]);
            y2 = max(y2, rec[3]);
            
            area += (rec[2] - rec[0]) * (rec[3] - rec[1]);
            vector<string> points(4);
            points[0] = to_string(rec[0]) + " " + to_string(rec[1]);
            points[1] = to_string(rec[0]) + " " + to_string(rec[3]);
            points[2] = to_string(rec[2]) + " " + to_string(rec[1]);
            points[3] = to_string(rec[2]) + " " + to_string(rec[3]);
            
            for (int i = 0; i < points.size(); ++i)
            {
                if (table.find(points[i]) != table.end())
                {
                    table.erase(points[i]);
                }
                else
                {
                    table.insert(points[i]);
                }
            }
        }
        
        return table.size() == 4 && 
               table.count(to_string(x1) + " " + to_string(y1)) &&
               table.count(to_string(x1) + " " + to_string(y2)) &&
               table.count(to_string(x2) + " " + to_string(y1)) &&
               table.count(to_string(x2) + " " + to_string(y2)) &&
               area == (x2 - x1) * (y2 - y1);
    }
};
