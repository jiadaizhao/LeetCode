class TweetCounts {
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        table[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int delta = 60;
        if (freq == "hour") {
            delta = 3600;
        }
        else if (freq == "day") {
            delta = 86400;
        }
        
        vector<int> result;
        int t = startTime;
        while (t <= endTime) {
            int end = min(t + delta, endTime + 1);
            int count = 0;
            auto it = table[tweetName].lower_bound(t);
            while (it != table[tweetName].end() && *it < end) {
                ++it;
                ++count;
            }
            result.push_back(count);
            t += delta;
        }
        
        return result;
    }
    
private:
    unordered_map<string, multiset<int>> table;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
