class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int difx1 = coordinates[1][0] - coordinates[0][0];
        int dify1 = coordinates[1][1] - coordinates[0][1];
        for (int i = 2; i < coordinates.size(); ++i){
            int difx2 = coordinates[i][0] - coordinates[0][0];
            int dify2 = coordinates[i][1] - coordinates[0][1];
            if (difx2 * dify1 != difx1 * dify2)
                return false;
        }

        return true;
    }
};
