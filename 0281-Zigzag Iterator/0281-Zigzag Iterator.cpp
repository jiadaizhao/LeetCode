class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        begin1 = v1.begin();
        begin2 = v2.begin();
        end1 = v1.end();
        end2 = v2.end();
        printV1 = true;
    }

    int next() {
        if (begin1 == end1)
        {
            return *begin2++;
        }
        else if (begin2 == end2)
        {
            return *begin1++;
        }
        else
        {
            int val;
            if (printV1)
            {
                val = *begin1++;
            }
            else
            {
                val = *begin2++;
                
            }
            printV1 = !printV1;
            return val;
        }
    }

    bool hasNext() {
        return begin1 != end1 || begin2 != end2;
    }
    
private:
    bool printV1;
    vector<int>::iterator begin1, begin2;
    vector<int>::iterator end1, end2;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

 // Using queue to handle follow up k 1d vectors
 class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.begin() != v1.end())
        {
            Q.emplace(v1.begin(), v1.end());
        }
        if (v2.begin() != v2.end())
        {
            Q.emplace(v2.begin(), v2.end());
        }
    }

    int next() {
        auto p = Q.front();
        auto it = p.first;
        Q.pop();
        int val = *(it);
        if (++it != p.second)
        {
            Q.emplace(it, p.second);
        }
        return val;
    }

    bool hasNext() {
        return !Q.empty();
    }
    
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> Q;
};
