#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
string convert(const string &s){
    string res;
    for(int i=0;i<(int)s.size();++i){
        if(i+1<(int)s.size() && s[i+1]=='#'){
            if(s[i]=='C') res+='c';
            else if(s[i]=='D') res+='d';
            else if(s[i]=='F') res+='f';
            else if(s[i]=='G') res+='g';
            else if(s[i]=='A') res+='a';
            i++;
        }
        else
            res += s[i];
    }
    return res;
}
string solution(string m, vector<string> musicinfos) {
    int bestTime = -1;
    string answer = "(None)";
    string mMelody = convert(m);
    for(string msic:musicinfos){
        istringstream iss(msic);
        vector<string> mi(4);
        for(int i=0;i<4;++i)
            getline(iss, mi[i], ',');
        int bcTime = (stoi(mi[1].substr(0,2))*60 + stoi(mi[1].substr(3,2))) - (stoi(mi[0].substr(0,2))*60 + stoi(mi[0].substr(3,2)));
        string baseMel = convert(mi[3]);
        int mTime = baseMel.size();
        string mel = "";
        for(int i=0;i<(bcTime/mTime);++i)
            mel += baseMel;
        if(bcTime%mTime!=0)
            mel += baseMel.substr(0,bcTime%mTime);
        if(mel.find(mMelody)!=string::npos){
            if(bcTime>bestTime){
                bestTime = bcTime;
                answer = mi[2];
            }
        }
    }
    return answer;
}