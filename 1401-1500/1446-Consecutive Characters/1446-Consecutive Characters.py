import collections

class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n = len(arr)   
        preXor = [0] * (n+ 1)
        for i, num in enumerate(arr):
            preXor[i + 1] = preXor[i] ^ num
         
        count = 0
        for i in range(n - 1):
            for k in range(i + 1, n):
                if preXor[i] == preXor[k + 1]:
                    count += k - i
        return count


class Solution2:
    def countTriplets(self, arr: List[int]) -> int:     
        preXor = [0] * (len(arr) + 1)
        for i, num in enumerate(arr):
            preXor[i + 1] = preXor[i] ^ num
         
        preXorCount = collections.Counter([0])
        indexSum = collections.Counter()
        count = 0
        
        for k in range(len(arr)):
            count += k * preXorCount[preXor[k + 1]] - indexSum[preXor[k + 1]]
            preXorCount[preXor[k + 1]] += 1
            indexSum[preXor[k + 1]] += k + 1
        
        return count


# One pass
class Solution3:
    def countTriplets(self, arr: List[int]) -> int:     
        preXor = 0
        preXorCount = collections.Counter([0])
        indexSum = collections.Counter()
        count = 0
        
        for k, num in enumerate(arr):
            preXor ^= num
            count += k * preXorCount[preXor] - indexSum[preXor]
            preXorCount[preXor] += 1
            indexSum[preXor] += k + 1
        
        return count