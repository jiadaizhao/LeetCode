/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* left = NULL;
    Node* right = NULL;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return root;
        }
        stack<Node*> St;
        Node *node = root, *prev = nullptr, *head = nullptr, *tail = nullptr;
        while (!St.empty() || node) {
            if (node) {
                St.push(node);
                node = node->left;
            }
            else {
                node = St.top();
                if (head == nullptr) {
                    head = node;
                }
                tail = node;
                St.pop();
                if (prev) {
                    prev->right = node;
                }
                node->left = prev;
                prev = node;
                node = node->right;
            }
        }
        
        head->left = tail;
        tail->right = head;
        return head;
    }
};
