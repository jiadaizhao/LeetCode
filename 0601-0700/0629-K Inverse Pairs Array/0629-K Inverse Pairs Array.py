class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        presum = [0] * (1 + k)
        MOD = 1000000007
        for i in range(1, 1 + n):
            temp = [0] * (1 + k)
            temp[0] = 1
            for j in range(1, 1 + k):
                val = (presum[j] - (presum[j - i] if j >= i else 0)) % MOD
                temp[j] = (temp[j - 1] + val) % MOD
            presum = temp
        return (presum[k] - (presum[k - 1] if k > 0 else 0)) % MOD
