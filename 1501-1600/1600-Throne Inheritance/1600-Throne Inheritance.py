import collections
class ThroneInheritance:

    def __init__(self, kingName: str):
        self.king = kingName
        self.dead = set()
        self.children = collections.defaultdict(list)


    def birth(self, parentName: str, childName: str) -> None:
        self.children[parentName].append(childName)


    def death(self, name: str) -> None:
        self.dead.add(name)


    def getInheritanceOrder(self) -> List[str]:
        result = []
        def dfs(curr):
            if curr not in self.dead:
                result.append(curr)
            for child in self.children[curr]:
                dfs(child)
        dfs(self.king)
        return result
