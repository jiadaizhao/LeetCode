int MOD = 1000000007;
class Node {
public:
    int start, end;
    Node *left, *right;
    int count;
    long long total;
    Node(int start, int end) {
        this->start = start;
        this->end = end;
        left = right = nullptr;
        count = total = 0;
    }
    Node* getLeft() {
        if (left == nullptr) {
            left = new Node(start, (start + end) / 2);
        }
        return left;
    }
    
    Node* getRight() {
        if (right == nullptr) {
            right = new Node((start + end) / 2, end);
        }
        return right;
    }
    long long update(int i, int j, int val, vector<int>& X) {
        if (i >= j) return 0;
        if (start == i && end == j) {
            count += val;
        }
        else {
            int mid = (start + end) / 2;
            getLeft()->update(i, min(mid, j), val, X);
            getRight()->update(max(mid, i), j, val, X);
        }
        if (count > 0) {
            total = X[end] - X[start];
        }
        else {
            total = getLeft()->total + getRight()->total;
        }
        return total;
    }
};
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int> xs;
        vector<vector<int>> edges;
        for (auto rec : rectangles) {
            xs.insert(rec[0]);
            xs.insert(rec[2]);
            edges.push_back({rec[1], 1, rec[0], rec[2]});
            edges.push_back({rec[3], -1, rec[0], rec[2]});
        }
        
        sort(edges.begin(), edges.end());
        vector<int> X(xs.begin(), xs.end());
        unordered_map<int, int> table;
        int index = 0;
        for (int x : xs) {
            table[x] = index++;
        }
        long long currY = edges[0][0], currXSum = 0, area = 0;
        Node* root = new Node(0, X.size() - 1);
        for (auto edge : edges) {
            int y = edge[0], type = edge[1], x1 = edge[2], x2 = edge[3];
            area += currXSum * (y - currY);
            currXSum = root->update(table[x1], table[x2], type, X);
            currY = y;
        }
        return area % MOD;
    }
};
