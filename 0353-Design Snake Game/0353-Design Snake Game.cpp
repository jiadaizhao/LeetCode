class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        w = width;
        h = height;
        this->food = food;
        foodIndex = 0;
        head = {0, 0};
        snake.insert(0);
        Q.emplace(0, 0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if (direction == "U") {
            --head.first;
        }
        else if (direction == "L") {
            --head.second;
        }
        else if (direction == "R") {
            ++head.second;
        }
        else {
            ++head.first;
        }
        
        auto tail = Q.front();
        if (head.first < 0 || head.first >= h || head.second < 0 || head.second >= w || 
            (head.first != tail.first || head.second != tail.second) && snake.count(head.first * w + head.second)) {
            return -1;
        }
        
        
        if (foodIndex < food.size() && head.first == food[foodIndex].first && head.second == food[foodIndex].second) {
            ++foodIndex;
        }
        else {
            Q.pop();
            snake.erase(tail.first * w + tail.second);
        }
        
        Q.emplace(head.first, head.second);
        snake.insert(head.first * w + head.second);
        
        return Q.size() - 1;
    }
    
private:
    int w, h;
    queue<pair<int, int>> Q;
    pair<int, int> head;
    unordered_set<int> snake;
    int foodIndex;
    vector<pair<int, int>> food;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
 