class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        priority_queue<double,vector<double>, greater<double>> pq;
        double error = 0;
        for (string price : prices) {
            double p = stod(price);
            int f = floor(p);
            int c = ceil(p);
            target -= f;
            error += p - f;
            if (f != c) {
                pq.push((c - p) - (p - f));
            }
        }
        
        if (target < 0 || target > pq.size()) {
            return "-1";
        }
        
        while (target > 0) {
            error += pq.top();
            pq.pop();
            --target;
        }        

        string s = to_string(error);
        return s.substr(0, s.find(".") + 4);
    }
};
