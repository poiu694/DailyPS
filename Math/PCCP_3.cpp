#include <string>
#include <vector>
#include <iostream>

# define HOUR   3600
# define MINUTE 60
# define SECOND 60

using namespace std;

double	get_second_angle(int s)
{
    // 1초에 6도
	return (double) s * 6;
}

double	get_minute_angle(int m, int s)
{
    // 1분에 6도 + s에 의한 각도 (6 / 60)
	return (double) m * 6 + (double) (s * 0.1);
}

double	get_hour_angle(int h, int m, int s)
{
    // 1시간에 30도 + m에 의한 각도 (30 / 60) + s에 의한 각도 (30 / 60 / 60)
	return (double) (h % 12) * 30 + (double) (m * 0.5) + (double) (s * 0.5 / 60);
}

bool	is_collapse(double a1, double a2, double pa1, double pa2)
{
    if (pa1 == 354 && a1 == 0)
        a1 = 360;
	if (pa1 < pa2 && a1 > a2)
		return (true);
	return (false);
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer;
    int startTime = h1 * HOUR + m1 * MINUTE + s1;
    int endTime = h2 * HOUR + m2 * MINUTE + s2;

    answer = 0;
	double prevSecondAngle = get_second_angle(s1);
	double prevMinuteAngle = get_minute_angle(m1, s1);
	double prevHourAngle = get_hour_angle(h1, m1, s1);;
    for (int time=startTime; time<=endTime; time++)
    {
        int second = (time % SECOND);
        int minute = (time / MINUTE) % MINUTE;
        int hour = (time / HOUR);

        double secondAngle = get_second_angle(second); 
        double minuteAngle = get_minute_angle(minute, second); 
        double hourAngle = get_hour_angle(hour, minute, second); 

        if (hourAngle == secondAngle || minuteAngle == secondAngle)
        {
            answer++;
        }
        else
        {
            if (is_collapse(secondAngle, hourAngle, prevSecondAngle, prevHourAngle))
            {
                answer++;
            }
            if (is_collapse(secondAngle, minuteAngle, prevSecondAngle, prevMinuteAngle))
            {
                answer++;
            }
        }

		prevSecondAngle = secondAngle;
		prevMinuteAngle = minuteAngle;
		prevHourAngle = hourAngle;
    }
    return answer;
}
