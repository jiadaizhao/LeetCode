class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        table1 = set(wordlist)
        table2 = {word.lower() : word for word in wordlist[::-1]}
        table3 = {}
        for word in wordlist[::-1]:
            temp = []
            for c in word.lower():
                if c in 'aeiou':
                    temp.append('#')
                else:
                    temp.append(c)
            table3[''.join(temp)] = word

        result = [''] * len(queries)

        for i in range(len(queries)):
            query = queries[i]
            if query in table1:
                result[i] = query
            elif query.lower() in table2:
                result[i] = table2[query.lower()]
            else:
                temp = list(query.lower())
                for j in range(len(temp)):
                    if temp[j] in 'aeiou':
                        temp[j] = '#'
                key = ''.join(temp)
                if key in table3:
                    result[i] = table3[key]
        
        return result
