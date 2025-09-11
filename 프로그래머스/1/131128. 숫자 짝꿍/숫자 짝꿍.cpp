#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int cntX[10]={0}, cntY[10]={0};
    for(char x:X)   cntX[x-'0']++;
    for(char y:Y)   cntY[y-'0']++;
    for(int i=9;i>=0;--i){
        int xy = (cntX[i]>cntY[i])?cntY[i]:cntX[i];
        answer.append(xy,char('0'+i));
    }
    if(answer.empty())  answer.append("-1");
    else if(answer[0]=='0'){
        answer.clear();
        answer.append("0");
    }
    return answer;
}