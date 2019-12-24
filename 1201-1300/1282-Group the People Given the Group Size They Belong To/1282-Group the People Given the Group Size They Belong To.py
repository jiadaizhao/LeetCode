import collections
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        table = collections.defaultdict(list)
        result = []
        for i, gs in enumerate(groupSizes):
            if gs == 1:
                result.append([i])
            else:
                table[gs].append(i)
                
        for k, v in table.items():
            for i in range(0, len(v), k):
                result.append(v[i: i + k])
        return result
