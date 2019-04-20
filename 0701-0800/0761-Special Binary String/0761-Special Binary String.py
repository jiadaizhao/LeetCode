class Solution:
    def makeLargestSpecial(self, S: str) -> str:
        strs = []
        start = bal = 0
        for i, c in enumerate(S):
            if c == '1':
                bal += 1
            else:
                bal -= 1
                
            if bal == 0:
                strs.append('1{}0'.format(self.makeLargestSpecial(S[start+1 : i])))
                start = i + 1
        
        return ''.join(sorted(strs, reverse=True))
