class Solution:
    def sampleStats(self, count: List[int]) -> List[float]:
        # minimum, maximum, mean, median, and mode
        result = [0] * 5
        for i, c in enumerate(count):
            if c > 0:
                result[0] = float(i)
                break

        for i in range(255, -1, -1):
            if count[i] > 0:
                result[1] = float(i)
                break

        total = s = mode = 0
        for i, c in enumerate(count):
            s += i * c
            total += c
            if c > count[mode]:
                mode = i

        result[2] = s / total
        result[4] = float(mode)
        
        curr = 0
        target = (total + 1) // 2
        odd = total & 1
        first = -1
        for i, c in enumerate(count):
            if c > 0:
                curr += c
                if curr >= target:
                    if odd or (first == -1 and curr > target):
                        result[3] = float(i)
                        break
                    if first == -1:
                        first = i
                    else:
                        result[3] = (first + i) / 2
                        break

        return result
