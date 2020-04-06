class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        inMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int start = inMap[id].second;
        string route = inMap[id].first + '-' + stationName;
        outMap[route].first += t - start;
        ++outMap[route].second;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto [time, count] = outMap[startStation + '-' + endStation];
        return (double)time / count;
    }
    
private:
    unordered_map<int, pair<string, int>> inMap;
    unordered_map<string, pair<int, int>> outMap;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
