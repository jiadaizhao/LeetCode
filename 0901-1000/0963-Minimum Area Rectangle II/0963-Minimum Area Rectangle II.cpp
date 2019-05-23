class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        vector<complex<double>> cp(points.size());
        for (int i = 0; i < points.size(); ++i) {
            cp[i] = complex(points[i][0], points[i][1]);
        }
        
        unordered_map<string, vector<pair<int, int>>> table;
        for (int i = 0; i < cp.size(); ++i) {
            for (int j = i + 1; j < cp.size(); ++j) {
                auto center = (cp[i] + cp[j]);
                center /= 2;
                double radius = abs(center - cp[i]);
                string key = to_string(real(center)) + " " + to_string(imag(center)) + " " + to_string(radius);
                table[key].push_back({i, j});                
            }
        }
        
        double minArea = -1;
        for (auto p : table) {
            for (int i = 0; i < p.second.size(); ++i) {
                for (int j = i + 1; j < p.second.size(); ++j) {
                    auto P = cp[p.second[i].first], Q = cp[p.second[i].second];
                    auto S = cp[p.second[j].first];
                    double area = abs(P - S) * abs(Q - S);
                    if (minArea == -1 || area < minArea) {
                        minArea = area;
                    }
                }
            }
        }
        
        return (minArea == -1) ? 0 : minArea;
    }
};
