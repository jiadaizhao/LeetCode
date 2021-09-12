class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        table = {}
        result = []
        for name in names:
            if name in table:
                num = table[name]
                curr = name
                while curr in table: 
                    curr = name + '({})'.format(num)
                    num += 1
                result.append(curr)
                table[curr] = 1
                table[name] = num
            else:
                result.append(name)
                table[name] = 1
        return result
