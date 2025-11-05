#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int idx = 0;
    string num;
    while(idx<s.size()){
        if(s[idx]=='o'||(s[idx]=='t'&&s[idx+1]=='w')||(s[idx]=='s'&&s[idx+1]=='i')){
            if(s[idx]=='o') num+='1';
            else if(s[idx]=='t') num+='2';
            else if(s[idx]=='s') num+='6';
            idx+=3;
        }
        else if(s[idx]=='z'||(s[idx]=='f'&&s[idx+1]=='o')||(s[idx]=='f'&&s[idx+1]=='i')||s[idx]=='n'){
            if(s[idx]=='z') num+='0';
            else if(s[idx]=='f'&&s[idx+1]=='o') num+='4';
            else if(s[idx]=='f'&&s[idx+1]=='i') num+='5';
            else if(s[idx]=='n') num+='9';
            idx+=4;
        }
        else if((s[idx]=='t'&&s[idx+1]=='h')||(s[idx]=='s'&&s[idx+1]=='e')||(s[idx]=='e'&&s[idx+1]=='i')){
            if(s[idx]=='t') num+='3';
            else if(s[idx]=='s') num+='7';
            else if(s[idx]=='e') num+='8';
            idx+=5;
        }
        else if((s[idx]-'0')>=0&&(s[idx]-'0')<=9){
            num+=s[idx];
            idx++;
        }
    }
    int answer = stoi(num);
    return answer;
}