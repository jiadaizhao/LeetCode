class Leaderboard {
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        table.erase({scores[playerId], playerId});
        scores[playerId] += score;
        table.insert({scores[playerId], playerId}); 
    }
    
    int top(int K) {
        int total = 0;
        for (auto it = table.rbegin(); it != table.rend() && K > 0; ++it) {
            total += it->first;
            --K;
        }
        
        return total;
    }
    
    void reset(int playerId) {
        table.erase({scores[playerId], playerId});
        scores[playerId] = 0;
    }
    
private:
    unordered_map<int, int> scores;
    set<pair<int, int>> table;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
