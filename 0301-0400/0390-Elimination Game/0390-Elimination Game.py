class Solution:
    def lastRemaining(self, n: 'int') -> 'int':
        left = True
        head = 1
        step = 1
        while n > 1:
            if left or (n&1):
                head += step
            step *= 2
            n //= 2
            left = not left
        return head
