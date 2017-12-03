class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<Cell> pq;
        int k = primes.size();
        vector<int> ugly(n);
        ugly[0] = 1;
        
        for (int j = 0; j < k; ++j) {
            pq.emplace(primes[j], 0, primes[j]);
        }
        
        for (int i = 1; i < n; ++i) {
            ugly[i] = pq.top().value;
            while (pq.top().value == ugly[i]) {
                int index = pq.top().index + 1;
                int prime = pq.top().prime;
                pq.pop();
                pq.emplace(ugly[index] * prime, index, prime);
            }
        }
        
        return ugly[n - 1];
    }
    
private:
    struct Cell {
        int value;
        int index;
        int prime;
        Cell(int v, int i, int p) : value(v), index(i), prime(p){}
        bool operator < (const Cell &c) const {
            return value > c.value;
        }
    };
};
