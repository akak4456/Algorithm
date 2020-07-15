class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minutesAngle = minutes*6;
        double hourAngle = hour*30 + (minutes*1.0)/2;
        double diff = abs(minutesAngle-hourAngle);
        return min(diff,360-diff);
    }
};