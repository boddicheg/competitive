class Solution {
public:
    bool judgeCircle(string moves) {
        int x_moves = 0;
        int y_moves = 0;
        for(const auto& c: moves)
        {
            if(c == 'U') x_moves++;
            if(c == 'D') x_moves--;
            if(c == 'R') y_moves++;
            if(c == 'L') y_moves--;
        }
        return x_moves == 0 && y_moves == 0;
    }
};