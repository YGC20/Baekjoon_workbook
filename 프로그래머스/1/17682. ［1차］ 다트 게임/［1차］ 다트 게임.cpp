#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string dartResult)
{
    int i, answer = 0;
    int len = dartResult.length();
    stack<int> score;
    string number = "";
    for(i=0; i<len; ++i) {
        char ch = dartResult[i];
        if(isdigit(ch)) { number += ch; }
        else {
            int num = stoi(number); number.clear();
            switch(ch) {
                case 'D':
                    num = num * num;
                    break;
                case 'T':
                    num = num * num * num;
                    break;
            }
            
            char opt = dartResult[i+1];
            if(opt == '*' || opt == '#') {
                int temp = 0;
                switch(opt) {
                    case '*':
                        temp = score.top(); score.pop();
                        score.push(temp * 2);
                        num *= 2;
                        break;
                    case '#':
                        num = -num;
                        break;
                }
                i++;
            }
            score.push(num);
        }
    }
    while(!score.empty()) {
        answer += score.top();
        score.pop();
    }
    return answer;
}