class FileSystem:

    def __init__(self):
        self.table = {'': -1}

    def createPath(self, path: str, value: int) -> bool:
        parent = path[:path.rfind('/')]
        if parent not in self.table or path in self.table:
            return False
        else:
            self.table[path] = value
            return True

    def get(self, path: str) -> int:
        return self.table.get(path, -1)


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.createPath(path,value)
# param_2 = obj.get(path)
