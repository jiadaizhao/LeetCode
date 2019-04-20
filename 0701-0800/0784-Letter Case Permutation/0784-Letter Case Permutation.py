class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        count = sum(c.isalpha() for c in S)
        result = []
        for i in range(1 << count):
            b = 0
            curr = []
            for c in S:
                if c.isdigit():
                    curr.append(c)
                else:
                    if (1 << b) & i:
                        curr.append(c.upper())
                    else:
                        curr.append(c.lower())
                    b += 1
            result.append(''.join(curr))
        return result
