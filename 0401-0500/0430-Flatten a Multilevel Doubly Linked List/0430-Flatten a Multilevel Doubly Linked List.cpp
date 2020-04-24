/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        return dfs(head).first;
    }
    
private:
    pair<Node*, Node*> dfs(Node* head) {
        Node *node = head, *tail = nullptr, *prev = nullptr;
        while (node) {
            while (node && node->child == nullptr) {
                prev = node;
                node = node->next;
            }
            if (node) {
                auto p = dfs(node->child);
                node->child = nullptr;
                Node* next = node->next;
                p.second->next = next;
                node->next = p.first;
                p.first->prev = node;
                if (next) {
                    next->prev = p.second;
                }
                tail = p.second;
            }
            else {
                tail = prev;
            }
        }
        return {head, tail};
    }
};
