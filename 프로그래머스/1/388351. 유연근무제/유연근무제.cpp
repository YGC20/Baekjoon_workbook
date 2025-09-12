#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int t=0;t<schedules.size();++t){
        int hour = schedules[t]/100;
        int minute = schedules[t]%100+10;
        if(minute>=60){
            hour++; minute-=60;
        }
        int day = startday;
        int score = 0;
        for(int attendance:timelogs[t]){
            if(day>7)   day = 1;
            if(day<=5){
                int at_hour = attendance/100;
                int at_minute = attendance%100;
                if(at_hour==hour&&at_minute<=minute)    score++;
                else if(at_hour<hour)   score++;
            }
            day++;
        }
        if(score>=5)    answer++;
    }
    return answer;
}