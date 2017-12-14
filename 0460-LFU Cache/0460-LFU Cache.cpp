class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        
        Node* node = cacheMap[key];
        freqMap[node->freq].erase(node->it);
        ++node->freq;
        freqMap[node->freq].push_front(key);
        node->it = freqMap[node->freq].begin();
        if (freqMap[minFreq].size() == 0) {
            minFreq = node->freq;
        }
        
        return node->val;
    }
    
    void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        
        if (get(key) == -1) {
            if (cacheMap.size() == capacity) {
                int popKey = freqMap[minFreq].back();
                cacheMap.erase(popKey);
                freqMap[minFreq].pop_back();
            }
            
            Node* node = new Node(value);
            minFreq = 1;
            freqMap[1].push_front(key);
            node->it = freqMap[1].begin();
            cacheMap[key] = node;
        }
        else {
            cacheMap[key]->val = value;
        }
    }
    
private:
    struct Node {
        int val;
        int freq;
        list<int>::iterator it;
        Node(): freq(1) {}
        Node(int v): val(v), freq(1) {}
    };
    int minFreq;
    int capacity;
    unordered_map<int, Node*> cacheMap;
    unordered_map<int, list<int>> freqMap;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 