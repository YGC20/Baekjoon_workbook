#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    int timeFee, overTime;
    vector<int> result;
    map<string, int> parkTime;
    map<string, pair<int, bool>> parking;
    
    for(auto& r : records) {
        int time = stoi(r.substr(0, 2)) * 60 + stoi(r.substr(3, 2));
        string num = r.substr(6, 4);
        bool io = (r.substr(11) == "IN")?true:false;
        
        if(parking.find(num) == parking.end() || !parking[num].second) {
            parking[num] = {time, io};
        } else {
            timeFee = time - parking[num].first;
            parking[num].second = io;
            parkTime[num] += timeFee;
        }
    }
    
    for(auto& p : parking) {
        if(p.second.second) {
            timeFee = 1439 - p.second.first;
            parkTime[p.first] += timeFee;
        }
    }
    
    for(auto& pt : parkTime) {
        overTime = ((pt.second - fees[0]) < 0)?0:(pt.second - fees[0]);
        timeFee = fees[1] + ceil(overTime / (float)(fees[2])) * fees[3];
        result.push_back(timeFee);
    }
    return result;
}