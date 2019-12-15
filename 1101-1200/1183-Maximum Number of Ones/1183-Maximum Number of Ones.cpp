class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<int> result;
        for (int i = 0; i < sideLength; ++i) {
            for (int j = 0; j < sideLength; ++j) {
                result.push_back(((width - 1 - i) / sideLength + 1) * ((height - 1 - j) / sideLength + 1));
            }
        }
        
        sort(result.begin(), result.end(), greater<int>());
        return accumulate(result.begin(), result.begin() + maxOnes, 0);
    }
};
