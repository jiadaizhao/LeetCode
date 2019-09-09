import collections
class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        table = collections.defaultdict(list)
        result = set()
        for t in transactions:
            entry = t.split(',')
            if int(entry[2]) > 1000:
                result.add(t)
            for history in table[entry[0]]:
                if abs(int(entry[1]) - int(history[1])) <= 60 and history[3] != entry[3]:
                    result.add(','.join(history))
                    result.add(t)
            
            table[entry[0]].append(entry)
        
        return list(result)
