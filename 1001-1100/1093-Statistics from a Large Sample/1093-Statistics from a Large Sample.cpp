class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        // minimum, maximum, mean, median, and mode
        vector<double> result(5);
        for (int i = 0; i < count.size(); ++i) {
            if (count[i] > 0) {
                result[0] = i;
                break;
            }
        }

        for (int i = count.size() - 1; i >= 0; --i) {
            if (count[i] > 0) {
                result[1] = i;
                break;
            }
        }

        int total = 0, mode = 0;
        double sum = 0;
        for (int i = 0; i < count.size(); ++i) {
            sum += i * count[i];
            total += count[i];
            if (count[i] > count[mode]) {
                mode = i;
            }
        }

        result[2] = sum / total;
        result[4] = mode;

        int curr = 0, target = (total + 1) / 2, first = -1;
        for (int i = 0; i < count.size(); ++i) {
            if (count[i] > 0) {
                curr += count[i];
                if (curr >= target) {
                    if ((total & 1) || (first == -1 && curr > target)) {
                        result[3] = i;
                        break;
                    }

                    if (first == -1) {
                        first = i;
                    }
                    else {
                        result[3] = ((double)first + i) / 2;
                        break;
                    }
                }
            }
        }

        return result;
    }
};
