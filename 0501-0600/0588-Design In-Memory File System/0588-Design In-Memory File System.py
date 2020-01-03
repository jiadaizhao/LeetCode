import collections
class Dir:

    def __init__(self):
        self.dirs = collections.defaultdict(Dir)
        self.files = {}

        
class FileSystem:

    def __init__(self):
        self.root = Dir()

    def ls(self, path: str) -> List[str]:
        node = self.root
        if path != '/':
            paths = path.split('/')[1:]
            for s in paths[:-1]:
                node = node.dirs[s]
            if paths[-1] in node.files:
                return [paths[-1]]
            else:
                node = node.dirs[paths[-1]]
        
        result = list(node.dirs.keys())
        result.extend(node.files.keys())
        return sorted(result)
    

    def mkdir(self, path: str) -> None:
        node = self.root
        for s in path.split('/')[1:]:
            node = node.dirs[s]

            
    def addContentToFile(self, filePath: str, content: str) -> None:
        node = self.root
        paths = filePath.split('/')[1:]
        for s in paths[:-1]:
            node = node.dirs[s]
        if paths[-1] in node.files:
            node.files[paths[-1]] += content
        else:
            node.files[paths[-1]] = content

            
    def readContentFromFile(self, filePath: str) -> str:
        node = self.root
        paths = filePath.split('/')[1:]
        for s in paths[:-1]:
            node = node.dirs[s]
        return node.files[paths[-1]]
        

# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)
