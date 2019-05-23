class Solution:
    def oddEvenJumps(self, A) -> int:
        largerIndex = [-1] * len(A)
        smallerIndex = [-1] * len(A)
        St = []
        for _, i in sorted((a, i) for i, a in enumerate(A)):
            while St and St[-1] < i:
                largerIndex[St.pop()] = i
            St.append(i)

        St = []
        for _, i in sorted((-a, i) for i, a in enumerate(A)):
            while St and St[-1] < i:
                smallerIndex[St.pop()] = i
            St.append(i)

        count = 1
        odd = [False] * len(A) # first jump is odd jump  
        even = [False] * len(A) # first jump is even jump
        odd[-1] = even[-1] = True
        for i in range(len(A) - 2, -1, -1):
            if largerIndex[i] != -1 and even[largerIndex[i]]:
                odd[i] = True
                count += 1
            
            if smallerIndex[i] != -1 and odd[smallerIndex[i]]:
                even[i] = True

        return count
