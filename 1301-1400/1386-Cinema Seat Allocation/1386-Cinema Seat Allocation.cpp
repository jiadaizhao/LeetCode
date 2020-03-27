class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> table;
        for (auto& seat : reservedSeats) {
            table[seat[0]] |= 1 << (seat[1] - 1);
        }
        int count = (n - table.size()) * 2;
        for (auto &[row, mask] : table) {
            if ((mask & 0b0111111110) == 0) {
                count += 2;
            }
            else if ((mask & 0b0111100000) == 0 || (mask & 0b0001111000) == 0 || (mask & 0b0000011110) == 0) {
                ++count;
            }
        }
        
        return count;
    }
};
