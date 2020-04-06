class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        dx = x_center - max(x1, min(x_center, x2))
        dy = y_center - max(y1, min(y_center, y2))
        return dx * dx + dy * dy <= radius * radius
