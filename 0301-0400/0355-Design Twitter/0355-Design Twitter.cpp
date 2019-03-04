int timeStamp = 0;

class Tweet {
public:
    int id;
    int time;
    Tweet* next;
    Tweet(int i) {
        id = i;
        time = timeStamp++;
        next = nullptr;
    }
};

class User {
public:
    int id;
    unordered_set<int> followed;
    Tweet* head;
    User() {}
    User(int i) {
        id = i;
        follow(id);
        head = nullptr;
    }

    void follow(int id) {
        followed.insert(id);
    }

    void unfollow(int id) {
        followed.erase(id);
    }

    void post(int id) {
        Tweet* t = new Tweet(id);
        t->next = head;
        head = t;
    }
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (userMap.find(userId) == userMap.end()) {
            userMap[userId] = User(userId);
        }

        userMap[userId].post(tweetId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        if (userMap.find(userId) == userMap.end()) {
            return result;
        }

        unordered_set<int> users = userMap[userId].followed;
        priority_queue<Tweet*, vector<Tweet*>, cmp> pq;
        for (int user : users) {
            Tweet* head = userMap[user].head;
            if (head) {
                pq.push(head);
            }            
        }

        int count = 0;
        while (!pq.empty() && count < 10) {
            Tweet* t = pq.top();
            pq.pop();
            result.push_back(t->id);
            ++count;
            if (t->next) {
                pq.push(t->next);
            }
        }

        return result;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (userMap.find(followerId) == userMap.end()) {
            userMap[followerId] = User(followerId);
        }

        if (userMap.find(followeeId) == userMap.end()) {
            userMap[followeeId] = User(followeeId);
        }

        userMap[followerId].follow(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId || userMap.find(followerId) == userMap.end() || userMap.find(followeeId) == userMap.end()) {
            return;
        }
        userMap[followerId].unfollow(followeeId);
    }

private:
    unordered_map<int, User> userMap;
    struct cmp {
        bool operator() (Tweet* t1, Tweet* t2) {
            return t1->time < t2->time;
        }
    };
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
 