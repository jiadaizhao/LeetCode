// Using Binary Index Tree
class NumArray {
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        
        bit = vector<int>(1 + n);
        numsCopy = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int index = i + 1;
        int diff = val - numsCopy[i];
        numsCopy[i] = val;
        while (index < bit.size()) {
            bit[index] += diff;
            index += (-index) & index;
        }
    }
    
    int sumRange(int i, int j) {
        return read(j + 1) - read(i);
    }
    
private:
    vector<int> bit;
    vector<int> numsCopy;
    int read(int index) {
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= (-index) & index;
        }
        
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

// Using Segment Tree 
class SegmentTreeNode {
public:
    int start, end, sum;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int sum) {
        this->start = start;
        this->end = end;
        this->sum = sum;
        this->left = this->right = NULL;
    }
};

class NumArray {
public:
    NumArray(vector<int> nums) {
        root = build(nums, 0, nums.size() - 1);
    }
    
    void update(int i, int val) {
        modify(root, i, val);
    }
    
    int sumRange(int i, int j) {
        return query(root, i, j);
    }
    
private:
    private:
    SegmentTreeNode* root;
    SegmentTreeNode* build(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        
        SegmentTreeNode* root = new SegmentTreeNode(start, end, nums[start]);
        if (start != end) {
            int mid = start + (end - start) / 2;
            root->left = build(nums, start, mid);
            root->right = build(nums, mid + 1, end);
            root->sum = root->left->sum + root->right->sum;
        }
        
        return root;
    }
    
    int query(SegmentTreeNode* root, int start, int end) {
        if (root->start == start && root->end == end) {
            return root->sum;
        }
        
        int mid = root->start + (root->end - root->start) / 2;
        int sum = 0;
        if (start <= mid) {
            sum += query(root->left, start, min(mid, end));
        }
        
        if (end > mid) {
            sum += query(root->right, max(mid + 1, start), end);
        }
        
        return sum;
    }
    
    void modify(SegmentTreeNode* root, int index, int value) {
        if (root->start == index && root->end == index) {
            root->sum = value;
            return;
        }
        
        int mid = root->start + (root->end - root->start) / 2;
        if (index >= root->start && index <= mid) {
            modify(root->left, index, value);
        }
        else if (index > mid && index <= root->end) {
            modify(root->right, index, value);
        }
        
        root->sum = root->left->sum + root->right->sum;
    }
};
