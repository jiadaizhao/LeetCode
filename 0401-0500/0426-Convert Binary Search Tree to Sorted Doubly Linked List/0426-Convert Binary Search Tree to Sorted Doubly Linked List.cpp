/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

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
        Node *curr = root, *prev = nullptr, *head = nullptr, *tail = nullptr;
        while (!St.empty() || curr) {
            if (curr) {
                St.push(curr);
                curr = curr->left;
            }
            else {
                curr = St.top();
                St.pop();
                if (prev == nullptr) {
                    head = curr;
                }
                else {
                    curr->left = prev;
                    prev->right = curr;
                }
                tail = curr;
                prev = curr;
                curr = curr->right;
            }
        }
        
        head->left = tail;
        tail->right = head;
        return head;
    }
};
