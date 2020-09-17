const int dy[4] = {1,0,-1,0};
const int dx[4] = {0,1,0,-1};
class Solution {
public:
    bool isRobotBounded(string instructions) {
       int direction = 0;
        int x = 0;
        int y = 0;
        for(int i=0;i<instructions.size();i++){
            if(instructions[i] == 'G'){
                x = x+dx[direction];
                y = y+dy[direction];
            }else if(instructions[i] == 'R'){
                direction = (direction+1)%4;
            }else if(instructions[i] == 'L'){
                direction = (direction-1+4)%4;
            }
        }
        return direction != 0 || (x==0&&y == 0);
    }
};