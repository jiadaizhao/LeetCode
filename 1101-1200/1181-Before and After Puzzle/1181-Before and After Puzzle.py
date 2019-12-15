import collections
class Solution:
    def beforeAndAfterPuzzles(self, phrases: List[str]) -> List[str]:
        first = collections.defaultdict(list)
        last = collections.defaultdict(list) 
        result = set()
        for p in phrases:
            index1 = p.rfind(' ')
            la = p[index1 + 1:]
            result.update([p + w for w in first[la]])            
            index2 = p.find(' ')
            fi = p[:index2] if index2 != -1 else p
            result.update([w + p for w in last[fi]])
            
            if index1 != -1:
                last[la].append(p[:index1 + 1])
            else:
                last[la].append('')
            if index2 != -1:
                first[fi].append(p[index2:])
            else:
                first[fi].append('')

        return sorted(result)
