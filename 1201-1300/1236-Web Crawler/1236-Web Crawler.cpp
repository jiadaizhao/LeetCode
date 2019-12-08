/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        queue<string> Q;
        Q.push(startUrl);
        unordered_set<string> visited;
        visited.insert(startUrl);
        string hostName = getHost(startUrl);
        while (!Q.empty()) {
            string curr = Q.front();
            Q.pop();
            for (string url : htmlParser.getUrls(curr)) {
                if (getHost(url) == hostName && !visited.count(url)) {
                    Q.push(url);
                    visited.insert(url);
                }
            }
        }
        
        return vector<string>(visited.begin(), visited.end());
    }
    
private:
    string getHost(string url) {
        int idx = url.find("/", 7);
        return url.substr(0, idx);
    }
};
