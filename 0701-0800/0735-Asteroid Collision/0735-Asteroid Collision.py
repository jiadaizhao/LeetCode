class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        St = []
        for a in asteroids:
            while St and St[-1] > 0 and St[-1] < -a:
                St.pop()
            if not St or St[-1] < 0 or a > 0:
                St.append(a)
            elif St[-1] == -a:
                St.pop()
        return St
