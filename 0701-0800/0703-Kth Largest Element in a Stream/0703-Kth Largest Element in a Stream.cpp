class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        this->k = k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
    
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */

struct Node {
    int val;
    Node *left;
    Node *right;
    int count;
    Node(int v, int c): val(v), left(NULL), right(NULL), count(c){}
};

class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        this->k = k;
        root = nullptr;
        for (int num : nums) {
            root = insert(root, num);
        }
    }
    
    int add(int val) {
        root = insert(root, val);
        return search(root, k);
    }
    
private:
    Node *root;
    int k;
    Node* insert(Node* root, int val) {
        if (root == nullptr) {
            return new Node(val, 1);
        }
        if (root->val < val) {
            root->right = insert(root->right, val);
        }
        else {
            root->left = insert(root->left, val);
        }
        ++root->count;
        return root;
    }
    
    int search(Node* root, int cnt) {
        int m = (root->right) ? root->right->count : 0;
        if (cnt == m + 1) {
            return root->val;
        }
        
        if (cnt <= m) {
            return search(root->right, cnt);
        }
        else {
            return search(root->left, cnt - m - 1);
        }
    } 
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
