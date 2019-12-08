# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
#class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """
import collections
class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        Q = collections.deque([startUrl])
        visited = set([startUrl])
        hostName = startUrl.split('/')[2]
        while Q:
            curr = Q.popleft()
            for url in htmlParser.getUrls(curr):
                hn = url.split('/')[2]
                if hn == hostName and url not in visited:
                    Q.append(url)
                    visited.add(url)
        return list(visited)
