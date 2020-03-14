class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> degree(n);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1 && ++degree[leftChild[i]] > 1) {
                return false;
            }
            if (rightChild[i] != -1 && ++degree[rightChild[i]] > 1) {
                return false;
            }
        }
        
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 0) {
                if (root == -1) {
                    root = i;
                }
                else {
                    return false;
                }
            }
        }
        
        return dfs(root, leftChild, rightChild) == n;
    }
    
private:
    int dfs(int curr, vector<int>& leftChild, vector<int>& rightChild) {
        if (curr == -1) {
            return 0;
        }
        return 1 + dfs(leftChild[curr], leftChild, rightChild) + dfs(rightChild[curr], leftChild, rightChild);
    }
};
