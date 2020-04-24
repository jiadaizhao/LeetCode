import collections
class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        order = collections.Counter()
        tables = set()
        foods = set()        
        for customer, table, food in orders:
            tables.add(table)
            foods.add(food)
            order[(table, food)] += 1
            
        result = [['Table'] + sorted(foods)]
        for table in sorted(tables, key=int):
            result.append([table] + [str(order[(table, food)]) for food in result[0][1:]])
        return result
