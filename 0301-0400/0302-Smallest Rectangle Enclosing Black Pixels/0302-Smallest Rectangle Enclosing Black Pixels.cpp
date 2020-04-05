class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        int left = findFirst(image, 0, y, true);
        int right = findLast(image, y, n - 1, true);
        int top = findFirst(image, 0, x, false);
        int bottom = findLast(image, x, m - 1, false);
        return (right - left + 1) * (bottom - top + 1);
    }
private:
    int findFirst(vector<vector<char>>& image, int low, int high, bool horizontal) {
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (hasBlack(image, mid, horizontal)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        
        return low;
    }
    
    int findLast(vector<vector<char>>& image, int low, int high, bool horizontal) {
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (hasBlack(image, mid, horizontal)) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }
        
        return low;
    }
    
    bool hasBlack(vector<vector<char>>& image, int c, bool vertical) {
        int m = image.size(), n = image[0].size();
        if (vertical) {
            for (int i = 0; i < m; ++i) {
                if (image[i][c] == '1') {
                    return true;
                }
            }
        }
        else {
            for (int j = 0; j < n; ++j) {
                if (image[c][j] == '1') {
                    return true;
                }
            }            
        }
        return false;
    }
};
