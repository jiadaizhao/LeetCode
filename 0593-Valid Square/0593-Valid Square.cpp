class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int, int> table;
        ++table[distanceSq(p1, p2)];
        ++table[distanceSq(p1, p3)];
        ++table[distanceSq(p1, p4)];
        ++table[distanceSq(p2, p3)];
        ++table[distanceSq(p2, p4)];
        ++table[distanceSq(p3, p4)];
        
        if (table.size() != 2)
        {
            return false;
        }
        
        auto side = table.begin();
        auto diag = table.rbegin();
        return side->second == 4 && diag->second == 2 && (side->first) * 2 == diag->first;        
    }
    
private:
    int distanceSq(vector<int>& p1, vector<int>& p2)
    {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};
