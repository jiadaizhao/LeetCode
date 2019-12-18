import collections
class Leaderboard:

    def __init__(self):
        self.table = collections.Counter()

        
    def addScore(self, playerId: int, score: int) -> None:
        self.table[playerId] += score


    def top(self, K: int) -> int:
        return sum(v for k, v in self.table.most_common(K))        

    
    def reset(self, playerId: int) -> None:
        self.table[playerId] = 0   


# Your Leaderboard object will be instantiated and called as such:
# obj = Leaderboard()
# obj.addScore(playerId,score)
# param_2 = obj.top(K)
# obj.reset(playerId)
