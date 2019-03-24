class Solution:
    def decodeString(self, s: str) -> str:
        St = []
        num = 0
        curr = ''
        for c in s:
            if c.isdigit():
                num = num*10 + int(c)
            elif c == '[':
                St.append([num, curr])
                num = 0
                curr = ''
            elif c == ']':
                count, prev = St.pop()
                curr = prev + count*curr
            else:
                curr += c
        return curr

class Solution2:
    def decodeString(self, s: str) -> str:
        i = 0
        def decode(s):
            nonlocal i
            result = []
            while i < len(s) and s[i] != ']':
                if s[i].isdigit():
                    num = 0
                    while i < len(s) and s[i].isdigit():
                        num = num*10 + int(s[i])
                        i += 1
                    
                    i += 1
                    temp = decode(s)
                    i += 1
                    result += temp*num
                else:
                    result.append(s[i])
                    i += 1
            return result
        return ''.join(decode(s))
