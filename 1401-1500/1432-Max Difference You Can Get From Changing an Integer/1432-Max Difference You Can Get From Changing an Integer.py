class Solution:
    def maxDiff(self, num: int) -> int:
        a = b = str(num)
        for d in a:
            if d != '9':
                a = a.replace(d, '9')
                break
        
        if b[0] == '1':            
            for d in b:
                if d not in '01':
                    b = b.replace(d, '0')
                    break
        else:
            b = b.replace(b[0], '1')
        
        return int(a) - int(b)
