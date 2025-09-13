#include <string>
#include <vector>

using namespace std;

int msCheck(string time){
    int minute = stoi(time.substr(0,2));
    int second = stoi(time.substr(3,2));
    return minute*60+second;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int videoLen = msCheck(video_len);
    int videoPos = msCheck(pos);
    int opStart = msCheck(op_start);
    int opEnd = msCheck(op_end);
    if(videoPos>=opStart&&videoPos<=opEnd)  videoPos=opEnd;
    for(string cmd:commands){
        if(videoPos>=opStart&&videoPos<=opEnd)  videoPos=opEnd;
        if(cmd=="next"){
            videoPos+=10;
            if(videoPos>videoLen)   videoPos=videoLen;
        }
        else if(cmd=="prev"){
            videoPos-=10;
            if(videoPos<0)  videoPos=0;
        }
        if(videoPos>=opStart&&videoPos<=opEnd)  videoPos=opEnd;
    }
    int minute = videoPos/60;
    string mm = (minute<10?"0":"")+to_string(minute);
    int second = videoPos%60;
    string ss = (second<10?"0":"")+to_string(second);
    answer = mm+":"+ss;
    return answer;
}