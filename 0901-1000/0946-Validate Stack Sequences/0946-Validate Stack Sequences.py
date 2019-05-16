class Solution:
    def validateStackSequences(self, pushed: 'List[int]', popped: 'List[int]') -> 'bool':
        St = []
        j = 0
        for i in pushed:
            St.append(i)
            while St and St[-1] == popped[j]:
                St.pop()
                j += 1
        return len(St) == 0
