class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> Q;
        Q.push_back(deck.back());
        for (int i = (int)(deck.size()) - 2; i >= 0; --i) {
            Q.push_front(Q.back());
            Q.pop_back();
            Q.push_front(deck[i]);
        }
        return vector<int>(Q.begin(), Q.end());
    }
};

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> Q;
        for (int i = 0; i < deck.size(); ++i) {
            Q.push(i);
        }
        vector<int> result(deck.size());
        for (int card : deck) {
            result[Q.front()] = card;
            Q.pop();
            if (Q.size()) {
                Q.push(Q.front());
                Q.pop();
            }
        }
        return result;
    }
};
