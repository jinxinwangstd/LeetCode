class SnakeGame {
public:
    /* Initialize your data structure here.
     * @param width - screen width.
     * @param height - screen height.
     * @param food - A list of food positions
     * E.g. food = [[1,1], [1,0]] means the first food is positioned at [1,1], and the second is at [1,0].
     */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        m = height;
        n = width;
        snake.push_front(0);
        positions.insert(0);
        for (int i = 0; i < food.size(); i++) {
            foods.push(id(food[i][0], food[i][1]));
        }
        dx["U"] = -1;
        dx["D"] = 1;
        dx["L"] = 0;
        dx["R"] = 0;
        dy["U"] = 0;
        dy["D"] = 0;
        dy["L"] = -1;
        dy["R"] = 1;
        return;
    }

    /* Move the snake.
     * @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
     * @return The game's score after the move. Return -1 if game is over.
     * Game over when snake cross the screen boundary or bites its body.
     */
    int move(string direction) {
        int head_x = snake.front() / n, head_y = snake.front() % n;
        int next_x = head_x + dx[direction], next_y = head_y + dy[direction];
        if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
            return -1;
        int next = id(next_x, next_y);
        if (next == foods.front()) {
            foods.pop();
        }
        else {
            int tail = snake.back();
            snake.pop_back();
            positions.erase(tail);
        }
        if (positions.count(next))
            return -1;
        snake.push_front(next);
        positions.insert(next);
        return snake.size() - 1; 
    }
private:
    deque<int> snake;
    set<int> positions;
    int m, n;
    queue<int> food;
    map<string, int> dx;
    map<string, int> dy;
    int id(int x, int y) {
        return x * n + y;
    }
};
