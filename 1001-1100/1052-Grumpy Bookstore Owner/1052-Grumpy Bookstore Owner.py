class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        curr = sum(customers[i] for i in range(len(customers)) if grumpy[i] == 0)
        for i in range(X):
            if grumpy[i]:
                curr += customers[i]
                
        maxNum = curr
        for i in range(X, len(customers)):
            if grumpy[i]:
                curr += customers[i]
            if grumpy[i - X]:
                curr -= customers[i - X]
            maxNum = max(maxNum, curr)
                
        return maxNum

# One pass
class Solution2:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        satisfied = make_satisfied = max_make_satisfied = 0
        for i in range(len(customers)):
            if grumpy[i] == 0:
                satisfied += customers[i]
            else:
                make_satisfied += customers[i]
            if i >= X and grumpy[i - X]:
                make_satisfied -= customers[i - X]
            max_make_satisfied = max(max_make_satisfied, make_satisfied)
                
        return satisfied + max_make_satisfied
