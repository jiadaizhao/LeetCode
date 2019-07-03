import collections
class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
        table = collections.Counter()
        vl = sorted(zip(values, labels), reverse=True)
        maxVal = 0
        for value, label in vl:
            if table[label] < use_limit:
                maxVal += value
                table[label] += 1
                num_wanted -= 1
                if num_wanted == 0:
                    break

        return maxVal
