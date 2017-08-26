class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = image[0].size();
        int left = findFirst(image, 0, y, true);
        int right = findLast(image, y, n - 1, true);
        int top = findFirst(image, 0, x, false);
        int bottom = findLast(image, x, m - 1, false);
        return (right - left + 1) * (bottom - top + 1);
    }
private:
    int findFirst(vector<vector<char>>& image, int start, int end, bool horizontal)
    {
        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (hasBlack(image, mid, horizontal))
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        
        if (hasBlack(image, start, horizontal))
        {
            return start;
        }
        else
        {
            return end;
        }
    }
    
    int findLast(vector<vector<char>>& image, int start, int end, bool horizontal)
    {
        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (hasBlack(image, mid, horizontal))
            {
                start = mid;
            }
            else
            {
                end = mid - 1;
            }
        }
        
        if (hasBlack(image, end, horizontal))
        {
            return end;
        }
        else
        {
            return start;
        }
    }
    
    bool hasBlack(vector<vector<char>>& image, int c, bool vertical)
    {
        int m = image.size();
        int n = image[0].size();
        if (vertical)
        {
            for (int i = 0; i < m; ++i)
            {
                if (image[i][c] == '1')
                {
                    return true;
                }
            }
        
            return false;
        }
        else
        {
            for (int j = 0; j < n; ++j)
            {
                if (image[c][j] == '1')
                {
                    return true;
                }
            }
            
            return false;
        }
    }
};
