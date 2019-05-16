import collections
# Do reverse operation
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort()
        for i in range(len(deck) - 2, -1, -1):
            deck[i + 1:] = deck[-1:] + deck[i + 1: -1]
        return deck

# use queue to optimize time complexity              
class Solution2:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort()
        Q = collections.deque([deck[-1]])
        for i in range(len(deck) - 2, -1, -1):
            Q.appendleft(Q.pop())
            Q.appendleft(deck[i])
        return list(Q)

class Solution3:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        Q = collections.deque(range(len(deck)))
        result = [None] * len(deck)
        for card in sorted(deck):
            result[Q.popleft()] = card
            if Q:
                Q.append(Q.popleft())
        return result
