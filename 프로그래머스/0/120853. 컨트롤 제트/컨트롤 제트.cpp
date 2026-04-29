#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(string s) {
    int answer = 0;
    stringstream ss(s);
    string cmd;
    int lastNum = 0;
    
    while(ss>>cmd) {
        if(cmd == "Z")
            answer -= lastNum;
        else {
            lastNum = stoi(cmd);
            answer += lastNum;
        }
    }
    return answer;
}