class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<cell>, cmp> pq;
        int k = primes.size();
        vector<int> ugly(n);
        ugly[0] = 1;
        
        for (int j = 0; j < k; ++j)
        {
            pq.emplace(primes[j], 0, primes[j]);
        }
        
        for (int i = 1; i < n; ++i)
        {
            ugly[i] = pq.top().value;
            while (pq.top().value == ugly[i])
            {
                cell c = pq.top();
                pq.pop();
                ++(c.index);
                pq.emplace(ugly[c.index] * c.prime, c.index, c.prime);
            }
        }
        
        return ugly[n - 1];
    }
    
private:
    struct cell {
        int value;
        int index;
        int prime;
        cell(int v, int i, int p) : value(v), index(i), prime(p){}
    };
    
    struct cmp
    {
        bool operator() (cell c1, cell c2)
        {
            return c1.value > c2.value;
        }
    };
};
