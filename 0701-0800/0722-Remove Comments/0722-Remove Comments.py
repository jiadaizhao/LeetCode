class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        result = []
        inBlock = False
        for s in source:
            if not inBlock:
                newLine = []
            i = 0
            while i < len(s):
                if not inBlock:
                    if s[i:i + 2] == '/*':
                        inBlock = True
                        i += 2
                    elif s[i:i + 2] == '//':
                        break
                    else:
                        newLine.append(s[i])
                        i += 1
                elif s[i:i+2] == '*/':
                        inBlock = False
                        i += 2
                else:
                    i += 1
                
            if newLine and not inBlock:
                result.append(''.join(newLine))
        return result
