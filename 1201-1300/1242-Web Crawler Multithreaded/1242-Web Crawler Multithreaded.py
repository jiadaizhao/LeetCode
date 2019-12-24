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
from concurrent.futures import ThreadPoolExecutor
from threading import Lock
import collections

class Solution:            
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        queue = collections.deque([startUrl])
        curr_hostname = startUrl.split('/')[2]
        visited = set([startUrl])
        lock = Lock()
        def downloadUrl(curr_url):
            next_urls = htmlParser.getUrls(curr_url)
        
            # Use Lock to protect shared states.
            with lock:
                for url in next_urls:
                    if url not in visited and curr_hostname == url.split('/')[2]:
                        queue.append(url)
                        visited.add(url)
        
		# Limit to 10 worker threads
        executor = ThreadPoolExecutor(max_workers=10)
        
        while queue:
            curr_url = queue.popleft()

            url_list = []
			# Add at least first URL from the queue
            url_list.append(curr_url)

			# If there are still URLs in the queue, add to the list 
            while queue:
                curr_url = queue.popleft()
                url_list.append(curr_url)
            
            executor_list = []
			# Execute this batch of threads with threadpool
            for i in range(len(url_list)):
                executor_list.append(executor.submit(downloadUrl, url_list[i]))
                
			# Main thread waiting for the above threads to finish
            for future in executor_list:
                future.result()
        
        # Shutdown ThreadPool executor
        executor.shutdown()
        
        return list(visited)
