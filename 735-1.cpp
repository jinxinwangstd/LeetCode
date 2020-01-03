class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (int asteroid : asteroids) {
            bool exploded = false;
            while (!s.empty()) {
                if (!(s.top() > 0 && asteroid < 0))
                    break;
                int top = s.top();
                if (abs(top) > abs(asteroid)) {
                    exploded = true;
                    break;
                }
                if (abs(top) == abs(asteroid)) {
                    s.pop();
                    exploded = true;
                    break;
                }
                s.pop();
            }
            if (!exploded)
                s.push(asteroid);
        }
        int n = s.size();
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};

/*
 * Stack
 */
