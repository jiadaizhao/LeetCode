/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node *curr = root, *head = nullptr, *prev = nullptr;
        while (curr) {
            while (curr) {
                if (curr->left) {
                    if (prev) {
                        prev->next = curr->left;
                    }
                    else {
                        head = curr->left;
                    }
                    prev = curr->left;
                }
                
                if (curr->right) {
                    if (prev) {
                        prev->next = curr->right;
                    }
                    else {
                        head = curr->right;
                    }
                    prev = curr->right;
                }
                
                curr = curr->next;
            }
            
            curr = head;
            head = prev = nullptr;
        }
        return root;
    }
};
