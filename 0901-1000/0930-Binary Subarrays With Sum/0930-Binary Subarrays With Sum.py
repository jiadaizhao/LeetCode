class Solution:
    def numSubarraysWithSum(self, A: List[int], S: int) -> int:
        table = [0] * (len(A) + 1)
        table[0] = 1
        curr = count = 0
        for a in A:
            curr += a
            if curr >= S:
                count += table[curr - S]
            table[curr] += 1
        return count


# O(1) space with sliding widnow but slower :(
class Solution2:
    def numSubarraysWithSum(self, A: List[int], S: int) -> int:
        start = curr = count = 0
        for i in range(len(A)):
            curr += A[i]
            while curr > S and start < i:
                curr -= A[start]
                start += 1
            if curr == S:
                count += 1
                temp = start
                while temp < i and A[temp] == 0:
                    temp += 1
                    count += 1
        return count
