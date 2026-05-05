#include <string>
#include <vector>

using namespace std;

string solution(string rny_string)
{
    string answer = "";
    for(auto ms : rny_string) {
        if(ms=='m') answer+="rn";
        else answer+=ms;
    }
    return answer;
}