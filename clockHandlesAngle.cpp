class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12)
        {
            hour = 0;
        }
        double hourAngle = (hour * 30) + float(minutes)/2;
        double minuteAngle = (minutes * 360) / 60;
        
        std::cout<< hourAngle << " :: " << minuteAngle << "\n";
        double angle = fabs(hourAngle - minuteAngle);
        return std::min(360 - angle, angle);
        
    }
};
