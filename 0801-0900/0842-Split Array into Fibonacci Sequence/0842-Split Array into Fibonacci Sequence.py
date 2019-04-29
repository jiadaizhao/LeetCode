class Solution:
    def splitIntoFibonacci(self, S: str) -> List[int]:
        for i in range(1, min(10, len(S)//2) + 1):
            s1 = S[:i]
            if s1 != '0' and s1[0] == '0':
                break
            num1 = int(s1)
            for j in range(1, min(10, len(S) // 2) + 1):
                if len(S) - i - j < max(i, j):
                    break
                s2 = S[i: i+j]
                if j > 1 and s2[0] == '0':
                    break
                num2 = int(s2)
                path = [num1, num2]
                k = i + j
                while k < len(S):
                    num3 = path[-2] + path[-1]
                    s3 = str(num3)
                    if num3 <= (1 << 31) - 1 and S[k: k + len(s3)] == s3:
                        k += len(s3)
                        path.append(num3)
                    else:
                        break
                
                if k == len(S) and len(path) >= 3:
                    return path
        return []
