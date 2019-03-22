import heapq
timeStamp = 0

class Tweet:
    
    def __init__(self, i):
        global timeStamp
        self.id = i
        self.time = timeStamp
        timeStamp += 1
        self.next = None
        
class User:
    
    def __init__(self, i):
        self.id = i
        self.head = None
        self.followed = set()
        self.follow(i)
        
    def follow(self, id):
        self.followed.add(id)
        
    def unfollow(self, id):
        self.followed.discard(id)
        
    def post(self, id):
        t = Tweet(id)
        t.next = self.head
        self.head = t
    
class Twitter:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.userMap = {}

    def postTweet(self, userId: int, tweetId: int) -> None:
        """
        Compose a new tweet.
        """
        if userId not in self.userMap:
            self.userMap[userId] = User(userId)
            
        self.userMap[userId].post(tweetId)

    def getNewsFeed(self, userId: int) -> List[int]:
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        """
        if userId not in self.userMap:
            return []
        
        pq = []
        for user in self.userMap[userId].followed:
            head = self.userMap[user].head
            if head:
                heapq.heappush(pq, (-head.time, head))
                
        count = 0
        result = []
        while pq and count < 10:
            _, t = heapq.heappop(pq)
            result.append(t.id)
            count += 1
            if t.next:
                heapq.heappush(pq, (-t.next.time, t.next))
        
        return result
        

    def follow(self, followerId: int, followeeId: int) -> None:
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        """
        if followerId not in self.userMap:
            self.userMap[followerId] = User(followerId)
            
        if followeeId not in self.userMap:
            self.userMap[followeeId] = User(followeeId)
            
        self.userMap[followerId].follow(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        """
        if followerId != followeeId and followerId in self.userMap and followeeId in self.userMap:
            self.userMap[followerId].unfollow(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
