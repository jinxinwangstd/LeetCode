class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0 , v = 0;
        for (char move : moves) {
            if (move == 'U') 
                v--;
            else if (move == 'D')
                v++;
            else if (move == 'L')
                h--;
            else 
                h++;
        }
        return h == 0 && v == 0;
        
    }
};
