#include <string>
#include <vector>

using namespace std;

string solution(int age)
{
    string strAge = "";
    string tmp = to_string(age);
    for(auto t : tmp)
        strAge += char(t-'0'+97);
    return strAge;
}