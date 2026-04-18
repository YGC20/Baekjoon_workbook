#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    int strLen = str1.length();
    string answer = "";
    for(int i=0; i<strLen; i++) {
        answer+=str1[i];
        answer+=str2[i];
    }
    return answer;
}