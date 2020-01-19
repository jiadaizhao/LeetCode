class Solution:
    def isSolvable(self, words, result) -> bool:
        for word in words:
            if len(word) > len(result):
                return False

        words = [word[::-1] for word in words]
        result = result[::-1]
        c2i = [-1] * 26
        i2c = [False] * 10
        def dfs(idx, digit, s):
            if digit == len(result):
                return s == 0
            
            if idx == len(words):
                if c2i[ord(result[digit]) - ord('A')] != -1:
                    if s % 10 == c2i[ord(result[digit]) - ord('A')]:
                        return  dfs(0, digit + 1, s // 10)
                elif not i2c[s % 10]:
                    if digit == len(result) - 1 and s % 10 == 0:
                        return False
                    c2i[ord(result[digit]) - ord('A')] = s % 10
                    i2c[s % 10] = True
                    if dfs(0, digit + 1, s // 10):
                        return True
                    c2i[ord(result[digit]) - ord('A')] = -1
                    i2c[s % 10] = False
                return False

            if digit >= len(words[idx]):
                return dfs(idx + 1, digit, s)

            if c2i[ord(words[idx][digit]) - ord('A')] != -1:
                if digit == len(words[idx]) - 1 and len(words[idx]) > 1 and c2i[ord(words[idx][digit]) - ord('A')] == 0:
                    return False
                return dfs(idx + 1, digit, s + c2i[ord(words[idx][digit]) - ord('A')])

            for i in range(10):
                if i2c[i]:
                    continue
                if i == 0 and digit == len(words[idx]) - 1 and len(words[idx]) > 1:
                    continue
                c2i[ord(words[idx][digit]) - ord('A')] = i
                i2c[i] = True
                if dfs(idx + 1, digit, s + i):
                    return True
                c2i[ord(words[idx][digit]) - ord('A')] = -1
                i2c[i] = False

            return False

        return dfs(0, 0, 0)
