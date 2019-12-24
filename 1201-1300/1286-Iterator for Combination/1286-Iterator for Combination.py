import itertools
class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.combs = list(map(''.join, itertools.combinations(characters, combinationLength)))[::-1]

    def next(self) -> str:
        return self.combs.pop()

    def hasNext(self) -> bool:
        return self.combs


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
