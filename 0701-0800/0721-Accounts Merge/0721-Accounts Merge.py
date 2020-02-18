import collections
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        parent = [i for i in range(len(accounts))]
        table = {}
        def findParent(index):
            while parent[index] != index:
                parent[index] = parent[parent[index]]
                index = parent[index]
            return index
        
        for i, account in enumerate(accounts):
            name = account[0]
            for email in account[1:]:
                if email not in table:
                    table[email] = i
                else:
                    p1 = findParent(table[email])
                    p2 = findParent(i)
                    if p1 != p2:
                        parent[p2] = p1
        
        result = collections.defaultdict(list)
        for email, i in table.items():
            p = findParent(i)
            result[p].append(email)
        return [[accounts[i][0]] + sorted(emails) for i, emails in result.items()]
