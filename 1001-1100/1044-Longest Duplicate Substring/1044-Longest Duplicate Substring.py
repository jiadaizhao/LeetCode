import collections
class Solution:
    def longestDupSubstring(self, S: str) -> str:
        def search(S, num):
            BASE = 33
            MOD = (1 << 20) - 1
            table = collections.defaultdict(list)
            hashcode = 0
            p = pow(BASE, num, MOD)
            for i in range(len(S)):
                hashcode = (hashcode * BASE + ord(S[i])) % MOD
                if i < num - 1:
                    continue
                
                if i >= num:
                    hashcode = hashcode - (ord(S[i - num]) * p) % MOD
                    if hashcode < 0:
                        hashcode += MOD
                    if hashcode in table:
                        ss = S[i - num + 1: i + 1]
                        for j in table[hashcode]:
                            if S[j - num + 1: j + 1] == ss:
                                return ss

                table[hashcode].append(i)
            
            return ''

        low = 1
        high = len(S)
        maxLenS = ''
        while low < high:
            mid = (low + high) // 2
            res = search(S, mid)
            if res:
                maxLenS = res
                low = mid + 1
            else:
                high = mid

        return maxLenS
