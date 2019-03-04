/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        RandomListNode* p = head;
        while (p) {
            RandomListNode* np = new RandomListNode(p->label);
            np->next = p->next;
            np->random = p->random;
            p->next = np;
            p = np->next;
        }
        
        p = head;
        while (p) {
            if (p->next->random) {
                p->next->random = p->random->next;
            }
            
            p = p->next->next;
        }
        
        p = head;
        RandomListNode* nh = p->next;
        while (p) {
            RandomListNode* np = p->next;
            p->next = np->next;
            p = p->next;
            if (np->next) {
                np->next = np->next->next;
            }
        }
        
        return nh;
    }
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        unordered_map<RandomListNode*, RandomListNode*> table;
        RandomListNode* node = head;
        while (node) {
            if (table.find(node) == table.end()) {
                table[node] = new RandomListNode(node->label);
            }
            if (node->next) {
                if (table.find(node->next) == table.end()) {
                    table[node->next] = new RandomListNode(node->next->label);
                }
                table[node]->next = table[node->next];
            }
            if (node->random) {
                if (table.find(node->random) == table.end()) {
                    table[node->random] = new RandomListNode(node->random->label);
                }
                table[node]->random = table[node->random];
            }            
            node = node->next;
        }
        return table[head];
    }
};
