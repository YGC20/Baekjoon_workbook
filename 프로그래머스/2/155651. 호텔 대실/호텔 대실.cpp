#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Room {
    int start, end;
};

Room usingTime(vector<string>& se)
{
    Room temp;
    temp.start = (stoi(se[0].substr(0,2))) * 60 + stoi(se[0].substr(3,2));
    temp.end = (stoi(se[1].substr(0,2))) * 60 + stoi(se[1].substr(3,2));
    return temp;
}

int solution(vector<vector<string>> bookTime)
{
    vector<Room> checkInTime;
    for(auto& bt : bookTime) { checkInTime.push_back(usingTime(bt)); }
    sort(checkInTime.begin(), checkInTime.end(), [](const Room& a, const Room& b){ 
        if(a.start == b.start) { return a.end < b.end; }
        return a.start < b.start; 
    });

    int roomCnt = 0;
    vector<int> hotel;
    for(auto& cit : checkInTime) {
        bool checkIn = true;
        for(int& ht : hotel) {
            if(cit.start >= ht) { ht = cit.end + 10; checkIn = false; break; }
        }
        if(checkIn) { hotel.push_back(cit.end + 10); roomCnt++; }
    }
    return roomCnt;
}