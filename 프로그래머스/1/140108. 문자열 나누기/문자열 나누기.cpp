#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char first = s[0];
    int same=0, diff=0, flag=1;
    for(char c:s){
        if(flag==0){
            first=c;
            flag=1;
        }
        if(c==first)    same++;
        else diff++;
        if(same==diff){
            answer++;
            same=diff=flag=0;
        }
    }
    if(same!=0||diff!=0)    answer++;
    return answer;
}