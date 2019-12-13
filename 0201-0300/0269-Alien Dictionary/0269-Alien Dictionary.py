import collections
class Solution:
    def alienOrder(self, words: List[str]) -> str:
        letters = set()
        prev = ''
        graph = collections.defaultdict(set)
        for word in words:
            for c in word:
                letters.add(c)

            for a, b in zip(prev, word):
                if a != b:
                    graph[a].add(b)
                    break
            else:
                if len(prev) > len(word):
                    return ''

            prev = word

        degrees = collections.Counter()
        for v in graph.values():
            for c in v:
                degrees[c] += 1

        Q = collections.deque()
        result = []
        for c in letters:
            if degrees[c] == 0:
                Q.append(c)
                result.append(c)

        while Q:
            c = Q.popleft()
            for n in graph[c]:
                degrees[n] -= 1
                if degrees[n] == 0:
                    Q.append(n)
                    result.append(n)

        return ''.join(result) if len(result) == len(letters) else ''
