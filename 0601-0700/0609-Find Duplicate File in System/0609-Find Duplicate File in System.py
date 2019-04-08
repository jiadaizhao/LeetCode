class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        table = collections.defaultdict(list)
        for path in paths:
            dir, *files = path.split()
            for file in files:
                name, _, content = file.partition('(')
                table[content[:-1]].append(dir + '/' + name)
        return [v for v in table.values() if len(v) > 1]
