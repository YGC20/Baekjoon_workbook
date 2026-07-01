#include <iostream>
#include <string>
using namespace std;

bool solution(string s)
{
    int alpha[2] = {0};
    for(int i=0; i<s.length(); ++i) {
        if(s[i]=='p'||s[i]=='P') alpha[0]++;
        if(s[i]=='y'||s[i]=='Y') alpha[1]++;
    }
    return (alpha[0]!=alpha[1])?false:true;
}