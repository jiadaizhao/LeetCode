class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        total = sum(A)
        if total % 3:
            return False
        target = total // 3
        curr = count = 0
        tc = 2 if target else 3
        for a in A:
            curr += a
            if curr == target:                
                count += 1
                if count == tc:
                    return True
                curr = 0
        return False
