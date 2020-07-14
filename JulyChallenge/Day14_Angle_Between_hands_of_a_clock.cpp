/*

Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

Example 1:

Input: hour = 12, minutes = 30
Output: 165

Example 3:

Input: hour = 3, minutes = 15
Output: 7.5

*/

//Code:

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h=0;
        if(minutes==60) 
        {
            minutes=0;
            hour+=1;
        }
        if(hour>=12)
        {
            hour=0;
        }
        h=0.5*(hour*60+minutes);
        double m= minutes*6;
        double angle=abs(h-m);
        angle=(360-angle<angle)? 360-angle:angle;
        return angle;
        
        
    }
};
