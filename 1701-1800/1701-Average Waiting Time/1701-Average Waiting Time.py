import collections
class Solution:
    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        table = collections.defaultdict(list)
        for key, time in zip(keyName, keyTime):
            h, m = map(int, time.split(':'))
            table[key].append(h * 60 + m)
        
        result = []
        for name, time in table.items():
            time.sort()
            for i in range(2, len(time)):
                if time[i] - time[i - 2] <= 60:
                    result.append(name)
                    break
        return sorted(result)
