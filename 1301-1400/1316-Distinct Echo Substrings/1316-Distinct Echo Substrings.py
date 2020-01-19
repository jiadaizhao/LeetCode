class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        BASE = 33
        MOD = 10 ** 8 + 7
        n = len(text)
        hashcode = [0] * (1 + n)
        power = [0] * (1 + n)
        power[0] = 1
        for i in range(1, n + 1):
            hashcode[i] = (hashcode[i - 1] * BASE + ord(text[i - 1])) % MOD
            power[i] = power[i - 1] * BASE % MOD
        visited = set()
        def getHash(l, r):
            return (hashcode[r] - hashcode[l] * power[r - l] % MOD) % MOD
        
        for l in range(1, n // 2 + 1):
            for i in range(n - l * 2 + 1):
                hash1 = getHash(i, i + l)
                hash2 = getHash(i + l, i + 2 * l)
                if hash1 == hash2:
                    visited.add(hash1)
                    
        return len(visited)
