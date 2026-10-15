#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int strToTime(string time)
{
    int hour = stoi(time.substr(0,2));
    int minute = stoi(time.substr(3,2));
    return (hour * 60 + minute);
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    map<string, pair<int,int>> parkingTime;
    for(auto& rec : records) {
        int time = strToTime(rec.substr(0,5));
        string nums = rec.substr(6,4);
        string status = rec.substr(11);
        
        int timer;
        if(status == "IN") {
            timer = parkingTime[nums].first;
            parkingTime[nums] = { timer, time };
        } else {
            timer = time - parkingTime[nums].second;
            int useTime = parkingTime[nums].first + timer;
            parkingTime[nums] = { useTime, -1 };
        }
    }
    
    
    
    vector<int> answer;
    for(auto& pt : parkingTime) {
        if(pt.second.second != -1) { pt.second.first += (1439 - pt.second.second); }
        int money = 0;
        if(pt.second.first > fees[0]) {
            money = fees[1] + ceil((float)(pt.second.first - fees[0]) / fees[2]) * fees[3];
        } else {
            money = fees[1];
        }
        answer.push_back(money);
    }
    return answer;
}