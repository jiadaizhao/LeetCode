class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        begin = vec2d.begin();
        curr = 0;
        end = vec2d.end();
        while (begin != end && curr == begin->size()) {
            ++begin;
            curr = 0;
        }
    }

    int next() {
        int result = *(begin->begin() + curr);
        ++curr;
        while (begin != end && curr == begin->size()) {
            ++begin;
            curr = 0;
        }
        return result;
    }

    bool hasNext() {
        return begin != end;
    }
private:
    vector<vector<int>>::iterator begin, end;
    int curr;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
