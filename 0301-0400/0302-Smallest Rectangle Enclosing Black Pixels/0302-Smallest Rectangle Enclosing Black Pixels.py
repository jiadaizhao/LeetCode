class Solution:
    def minArea(self, image: List[List[str]], x: int, y: int) -> int:
        m, n = len(image), len(image[0])
        def hasBlack(index, vertical):
            if vertical:
                return any(image[i][index] == '1' for i in range(m))
            else:
                return any(image[index][j] == '1' for j in range(n))

        def findFirst(low, high, horizontal):
            while low < high:
                mid = (low + high) // 2
                if hasBlack(mid, horizontal):
                    high = mid
                else:
                    low = mid + 1
            return low

        def findLast(low, high, horizontal):
            while low < high:
                mid = (low + high + 1) // 2
                if hasBlack(mid, horizontal):
                    low = mid
                else:
                    high = mid - 1
            return low

        left = findFirst(0, y, True)
        right = findLast(y, n - 1, True)
        top = findFirst(0, x, False)
        bottom = findLast(x, m - 1, False)
        return (right - left + 1) * (bottom - top + 1)
