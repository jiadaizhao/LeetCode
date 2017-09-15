class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> result(2);
        int W;
        for (W = sqrt(area); W >= 1; --W)
        {
            if (area % W == 0)
            {
                break;
            }
        }
        
        result[0] = area / W;
        result[1] = W;
        return result;
    }
};
