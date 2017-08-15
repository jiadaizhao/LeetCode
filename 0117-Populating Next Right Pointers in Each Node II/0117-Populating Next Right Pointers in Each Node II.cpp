/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* curr = root;
        TreeLinkNode* head = nullptr;
        TreeLinkNode* prev = nullptr;
        while (curr)
        {
            while (curr)
            {
                if (curr->left)
                {
                    if (prev)
                    {
                        prev->next = curr->left;
                    }
                    else
                    {
                        head = curr->left;
                    }
                    prev = curr->left;
                }
                
                if (curr->right)
                {
                    if (prev)
                    {
                        prev->next = curr->right;
                    }
                    else
                    {
                        head = curr->right;
                    }
                    prev = curr->right;
                }
                
                curr = curr->next;
            }
            
            curr = head;
            head = nullptr;
            prev = nullptr;
        }
    }
};
