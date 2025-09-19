#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    for(int i=0;i<progresses.size();++i){
        days.push(ceil((100.0-progresses[i])/speeds[i]));
    }
    int current=days.front();
    int count=1;
    days.pop();
    while(!days.empty()){
        if(days.front()<=current){
            count++;
        }
        else{
            answer.push_back(count);
            count=1;
            current=days.front();
        }
        days.pop();
    }
    answer.push_back(count);
    return answer;
}