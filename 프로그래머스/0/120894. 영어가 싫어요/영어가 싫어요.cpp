#include <string>
#include <vector>
using namespace std;

long long solution(string numbers)
{
    string ans = "";
    int idx = 0;
    while(idx<numbers.size()) {
        auto first = numbers[idx];
        auto second = numbers[idx+1];
        
        if(first=='z') {
            ans+="0";
            idx+=4;
        }
        else if(first=='o') {
            ans+="1";
            idx+=3;
        }
        else if(first=='t') {
            if(second=='w') {
                ans+="2";
                idx+=3;
            }
            else if(second=='h') {
                ans+="3";
                idx+=5;
            }
        }
        else if(first=='f') {
            if(second=='o') {
                ans+="4";
            }
            else if(second=='i') {
                ans+="5";
            }
            idx+=4;
        }
        else if(first=='s') {
            if(second=='i') {
                ans+="6";
                idx+=3;
            }
            else if(second=='e') {
                ans+="7";
                idx+=5;
            }
        }
        else if(first=='e') {
            ans+="8";
            idx+=5;
        }
        else if(first=='n') {
            ans+="9";
            idx+=4;
        }
    }
    return stoll(ans);
}