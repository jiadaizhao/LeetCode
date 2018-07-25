/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
struct pairhash {
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &p) const {
        return hash<T>()(p.first) ^ hash<U>()(p.second);
    }
};

class Solution {
public:
    void cleanRoom(Robot& robot) {
        return dfs(robot, 0, 0);
    }
    
private:
    unordered_set<pair<int, int>, pairhash> visited;
    void dfs(Robot& robot, int row, int col) {
        if (visited.count({row, col})) {
            return;
        }
        
        robot.clean();
        visited.insert({row, col});
        if (moveUp(robot)) {
            dfs(robot, row - 1, col);
            moveDown(robot);
        }
        if (moveDown(robot)) {
            dfs(robot, row + 1, col);
            moveUp(robot);
        }
        if (moveLeft(robot)) {
            dfs(robot, row, col - 1);
            moveRight(robot);
        }
        if (moveRight(robot)) {
            dfs(robot, row, col + 1);
            moveLeft(robot);
        }
    }
    
    bool moveUp(Robot& robot) {
        return robot.move();
    }
    
    bool moveDown(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        bool ok = robot.move();
        robot.turnLeft();
        robot.turnLeft();
        return ok;
    }
    
    bool moveLeft(Robot& robot) {
        robot.turnLeft();
        bool ok = robot.move();
        robot.turnRight();
        return ok;
    }
    
    bool moveRight(Robot& robot) {
        robot.turnRight();
        bool ok = robot.move();
        robot.turnLeft();
        return ok;
    }
};
