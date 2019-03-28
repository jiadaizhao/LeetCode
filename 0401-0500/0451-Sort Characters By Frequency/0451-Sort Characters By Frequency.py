import collections
class Solution:
    def frequencySort(self, s: str) -> str:
        table = collections.Counter(s)
        buckets = ['' for _ in range(len(s) + 1)]
        for k, v in table.items():
            buckets[v] += k*v
   
        return ''.join(buckets[::-1])
