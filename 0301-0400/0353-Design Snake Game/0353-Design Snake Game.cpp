class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->width = width;
        this->height = height;
        this->food = food;
        foodIndex = 0;
        dq.emplace_back(0, 0);
        snake.insert(0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto head = dq.front();
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

        if (head.first < 0 || head.first >= height || head.second < 0 || head.second >= width) {
            return -1;
        }
        
        int loc = head.first * width + head.second;
        auto tail = dq.back();
        if (snake.count(loc) && (head.first != tail.first || head.second != tail.second)) {
            return -1;
        }
        
        if (foodIndex < food.size() && head.first == food[foodIndex][0] && head.second == food[foodIndex][1]) {
            ++foodIndex;            
        }
        else {
            dq.pop_back();
            snake.erase(tail.first * width + tail.second);
        }
        
        dq.emplace_front(head.first, head.second);
        snake.insert(head.first * width + head.second);
        return dq.size() - 1;
    }
    
private:
    int width, height;
    int foodIndex;
    vector<vector<int>> food;
    deque<pair<int, int>> dq;
    unordered_set<int> snake;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
