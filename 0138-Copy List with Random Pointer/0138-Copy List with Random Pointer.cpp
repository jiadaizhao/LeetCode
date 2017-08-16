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
        if (head == nullptr)
        {
            return nullptr;
        }
        RandomListNode* p = head;
        while (p)
        {
            RandomListNode* np = new RandomListNode(p->label);
            np->next = p->next;
            np->random = p->random;
            p->next = np;
            p = np->next;
        }
        
        p = head;
        while (p)
        {
            if (p->next->random)
            {
                p->next->random = p->random->next;
            }
            
            p = p->next->next;
        }
        
        p = head;
        RandomListNode* nh = p->next;
        while (p)
        {
            RandomListNode* np = p->next;
            p->next = np->next;
            p = p->next;
            if (np->next)
            {
                np->next = np->next->next;
            }
        }
        
        return nh;
    }
};
