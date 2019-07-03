class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        level = 1
        # 2 times of center location in each level
        center2 = [2]
        while (1 << level) <= label:
            center2.append(center2[-1] * 2 + 1)
            level += 1

        result = [0] * (level - 1) + [label]
        next = label // 2
        reverse = True
        for i in range(level - 2, -1, -1):
            if reverse:
                result[i] = center2[i] - next
            else:
                result[i] = next
            next //= 2
            reverse = not reverse
        
        return result
