/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return nullptr;
        }
        return construct(grid, 0, 0, grid.size() - 1, grid.size() - 1);
    }
    
private:
    Node* construct(vector<vector<int>>& grid, int row1, int col1, int row2, int col2) {        
        if (row1 == row2 && col1 == col2) {
            return new Node(grid[row1][col1], true);
        }
        
        Node* topLeft = construct(grid, row1, col1, (row1 + row2) / 2, (col1 + col2) / 2);
        Node* topRight = construct(grid, row1, (col1 + col2 + 1) / 2, (row1 + row2) / 2, col2);
        Node* bottomLeft = construct(grid, (row1 + row2 + 1) / 2, col1, row2, (col1 + col2) / 2);
        Node* bottomRight = construct(grid, (row1 + row2 + 1) / 2, (col1 + col2 + 1) / 2, row2, col2);
        bool val = topLeft->val;
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && 
            topRight->val == val && bottomLeft->val == val && bottomRight->val == val) {
            return new Node(val, true);
        }
        else {
            return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    }
};
