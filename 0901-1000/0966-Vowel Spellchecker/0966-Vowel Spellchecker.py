class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        raw = set(wordlist)
        cap = {word.lower() : word for word in wordlist[::-1]}
        vowel = {}
        for word in wordlist[::-1]:
            vowel[''.join(['#' if c in 'aeiou' else c for c in word.lower()])] = word

        result = [''] * len(queries)

        for i, query in enumerate(queries):
            if query in raw:
                result[i] = query
            elif query.lower() in cap:
                result[i] = cap[query.lower()]
            else:
                key = ''.join(['#' if c in 'aeiou' else c for c in query.lower()])
                if key in vowel:
                    result[i] = vowel[key]
        
        return result
